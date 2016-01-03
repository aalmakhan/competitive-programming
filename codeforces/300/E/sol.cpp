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

int n, m, total[222222], dp[222222], dp2[222222];
vector <int> e[222222];

void rec(int u, int l) {
  if (e[u].empty()) {
    total[u] = 1;
    dp[u] = 1;
    dp2[u] = 1;
    return;
  }
  forit (it, e[u]) {
    int v = *it;
    rec(v, l ^ 1);
    total[u] += total[v];
  }

  if (l == 0) {
    forit (it, e[u]) {
      int v = *it;
      dp[u] = max(dp[u], dp[v] + total[u] - total[v]);
    }
    int sum = 0;
    forit (it, e[u]) {
      int v = *it;
      sum += dp2[v];
    }
    dp2[u] = sum;
  } else {
    int sum = 0;
    forit (it, e[u]) {
      int v = *it;
      sum += (total[v] - dp[v] + 1);
    }
    dp[u] = total[u] - sum + 1;
    dp2[u] = total[u];
    forit (it, e[u]) {
      int v = *it;
      dp2[u] = min(dp2[u], dp2[v]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    e[u].pb(v);
  }
  rec(0, 0);
  printf("%d %d\n", dp[0], dp2[0]);
  return 0;
}
