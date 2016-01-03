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

int n, m, a[111111], b[111111];

void imp() {
  puts("IMPOSSIBLE");
  exit(0);
}

int main() {
  scanf("%d%d", &n, &m);
  int res = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    res = max(res, b[i]);
  }
  for (int i = 0; i < m - 1; i++) {
    int dx = a[i + 1] - a[i];
    int dy = abs(b[i + 1] - b[i]);
    if (dy > dx) {
      imp();
    }
    int cur = max(b[i + 1], b[i]) + (dx - dy) / 2;
    res = max(res, cur);
  }
  if (a[0] > 1) {
    res = max(res, b[0] + a[0] - 1);
  }
  if (a[m - 1] < n) {
    res = max(res, b[m - 1] + n - a[m - 1]);
  }
  printf("%d\n", res);
  return 0;
}
