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

const ll inf = (ll)1e18;
int n;
ll dp[55];
ll k;

ll calc(int n) {
  if (n <= 1) return 1;
  ll& res = dp[n];
  if (res != -1) return res;
  res = calc(n - 1) + calc(n - 2);
  if (res > inf) res = inf;
  return res;
}

int main() {
  scanf("%d", &n);
  cin >> k;
  memset(dp, -1, sizeof(dp));
  int add = 0;
  while (n > 0) {
    if (calc(n - 1) >= k) {
      printf("%d ", add + 1);
      add += 1;
      n--;
    } else {
      k -= calc(n - 1);
      printf("%d %d ", add + 2, add + 1);
      add += 2;
      n -= 2;
    }
  }
  puts("");
  return 0;
}
