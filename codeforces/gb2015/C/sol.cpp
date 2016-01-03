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

char s[555][555];
int n, m;
int a[555][555];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 1; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        if (j > 0 && s[i][j - 1] == '.')
          ++sum;
        if (i > 0 && s[i - 1][j] == '.')
          ++sum;
      }
      a[i][j] = sum;
      if (i > 0) {
        a[i][j] += a[i - 1][j];
      }
    }
  }
  int q;
  scanf("%d", &q);
  int r1, c1, r2, c2;
  while (q--) {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    --r1, --c1, --r2, --c2;
    int res = 0;
    if (r1 < r2 && c1 < c2) {
      res = a[r2][c2];
      res -= a[r1][c2];
      res -= a[r2][c1];
      res += a[r1][c1];
    }
    for (int i = r1; i < r2; i++) {
      if (s[i][c1] == '.' && s[i + 1][c1] == '.') {
        ++res;
      }
    }
    for (int j = c1; j < c2; j++) {
      if (s[r1][j] == '.' && s[r1][j + 1] == '.') {
        ++res;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
