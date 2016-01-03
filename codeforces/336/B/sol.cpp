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

bool pal[555][555];
int a[555], n, dp[555][555];

int calc(int l, int r) {
  if (r < l) return 0;
  if (l == r) return 1;
  int &res = dp[l][r];
  if (res != -1) return res;
  res = 1 + calc(l + 1, r);
  for (int i = l + 1; i <= r; i++) {
    if (a[i] == a[l]) {
      res = min(res, max(1, calc(l + 1, i - 1)) + calc(i + 1, r));
    }
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", calc(0, n - 1));
  return 0;
}
