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

double PREV[111111], dp[111111];
int n, m, x[111111];

int main() {
  scanf("%d%d", &n, &m);
  int xsum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    xsum += x[i];
  }
  if (m == 1) {
    printf("%.10lf\n", 1.0);
    return 0;
  }

  PREV[0] = 1.0;
  for (int k = 0; k < n; k++) {
    double cur = 0.0;
    int cx = x[k];
    for (int i = 0; i <= n * m; i++) {
      if (i >= m + 1) {
        cur -= PREV[i - m - 1];
      }
      dp[i] = cur;
      if (i >= cx) {
        dp[i] -= PREV[i - cx];
      }
      cur += PREV[i];
    }
    for (int i = 0; i <= n * m; i++) {
      //cout << dp[i] << " ";
      PREV[i] = dp[i];
    }
    //cout << endl;
  }
  double sum = 0;
  for (int i = 1; i < xsum; i++) {
    sum += PREV[i];
  }
  for (int i = 0; i < n - 1; i++) {
    sum /= (m - 1);
  }

  printf("%.10lf\n", sum + 1);
  return 0;
}
