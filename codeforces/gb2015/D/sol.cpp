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
typedef pair <pi, int> pii;
typedef vector <int> vi;
typedef long long ll;

const int mod = int(1e9) + 7;
int n, dp[5005][5005], an;
int color[5005][5005];
pii a[5005];
char s[5555];

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    color[1][i] = s[i] - '0';
  }
  for (int d = 2; d <= n; d++) {
    an = 0;
    for (int i = 0; i + d <= n; i++) {
      a[an++] = mp(mp(s[i] - '0', color[d - 1][i + 1]), i);
    }
    sort(a, a + an);
    pi pp = mp(-1, -1);
    int cn = 0;
    for (int i = 0; i < an; i++) {
      int pos = a[i].s;
      if (a[i].f > pp) {
        color[d][pos] = cn++;
        pp = a[i].f;
      } else {
        color[d][pos] = cn - 1;
      }
    }
  }
  //for (int d = 1; d <= n; d++) {
  //  for (int i = 0; i + d <= n; i++) {
  //    printf("%d ", color[d][i]);
  //  }
  //  puts("");
  //}

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = i; j < n; j++) {
      cur += dp[i][j];
      if (cur >= mod) {
        cur -= mod;
      }
      dp[i][j] = cur;

      int len = j - i + 1;
      if (j + len < n && s[j + 1] != '0') {
        if (color[len][i] < color[len][j + 1]) { 
          dp[j + 1][j + len] += cur;
          if (dp[j + 1][j + len] >= mod) {
            dp[j + 1][j + len] -= mod;
          }
        } else if (j + len + 1 < n) {
          dp[j + 1][j + len + 1] += cur;
          if (dp[j + 1][j + len + 1] >= mod) {
            dp[j + 1][j + len + 1] -= mod;
          }
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += dp[i][n - 1];
    if (res >= mod) res -= mod;
  }
  printf("%d\n", res);
  return 0;
}
