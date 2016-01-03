#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <cassert>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
#define I64d "%I64d"
#else
#define I64d "%lld"
#endif

typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

int n, a[111], deg[111], ans[111];
vector <int> res;
char s[111][111];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ans[i] = 1;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        ++deg[j];
      }
    }
  }
  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (deg[u] == a[u]) {
        v = u;
        break;
      }
    }
    if (v == -1) break;
    assert(a[v] > 0 && ans[v] == 1);
    ans[v] = 0;
    for (int i = 0; i < n; i++) if (s[v][i] == '1') {
      --deg[i];
    }
  }
  for (int i = 0; i < n; i++) {
    assert(deg[i] != a[i]);
    if (ans[i] == 1) {
      res.pb(i);
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    if (i > 0) putchar(' ');
    printf("%d", res[i] + 1);
  }
  puts("");
  return 0;
}
