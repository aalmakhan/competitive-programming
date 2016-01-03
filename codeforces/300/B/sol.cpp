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

int from[1111111], n;
int dp[1111111], ans[1111111], an;

bool ok(int x) {
  while (x != 0) {
    int t = x % 10;
    if (t > 1) {
      return false;
    }
    x /= 10;
  }
  return true;
}

void go(int x) {
  for (int i = x; i <= n; i++) {
    int t = dp[i - x];
    if (t != -1) {
      t++;
      if (dp[i] == -1 || dp[i] > t) {
        dp[i] = t;
        from[i] = i - x;
      }
    }
  }
}

int main() {
  memset(from, -1, sizeof(n));
  memset(dp, -1, sizeof(dp));
  from[0] = 0;
  dp[0] = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (ok(i)) {
      go(i);
    }
  }
  int now = n;
  while (now > 0) {
    ans[an++] = now - from[now];
    now = from[now];
  }
  printf("%d\n", an);
  for (int i = 0; i < an; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
