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

const int mod = int(1e9) + 7;
vector<bool> ans;
int n, m, z[1111111], y[1111111];
char p[1111111];

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", p);
  int len = strlen(p);
  ans.assign(n, false);
  for (int i = 0; i < m; i++) {
    scanf("%d", &y[i]);
    --y[i];
  }
  sort(y, y + m);

  int j = 0;
  for (int i = 1; i < len; i++) {
    if (j + z[j] > i) {
      z[i] = min(j + z[j] - i, z[i - j]);
    }
    while (i + z[i] < len && p[z[i]] == p[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }

  int prev = -1;
  for (int i = 0; i < m; i++) {
    int x = y[i];
    int st = x, fn = x + len;
    if (prev != -1 && prev + len > x) {
      if (z[x - prev] < prev + len - x) {
        puts("0");
        return 0;
      }
      st = prev + len;
    }

    for (int j = st; j < fn; ++j) {
      ans[j] = true;
    }
    prev = x;
  }

  ll res = 1;
  for (int i = 0; i < n; i++) {
    if (!ans[i]) {
      res = (res * 26) % mod;
    }
  }
  cout << res << endl;
  return 0;
}
