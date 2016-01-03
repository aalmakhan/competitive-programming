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

char s[111][111];
int a[111][111];
int col[111], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      a[i][j] = (s[i][j] == 'B' ? -1 : 1);
    }
  }
  int res = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j] != col[j]) {
        ++res;
        int x = a[i][j] - col[j];
        for (int k = j; k >= 0; k--) {
          col[k] += x;
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
