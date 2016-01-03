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

int n, a[111111], b[111111], q;
pi t[444444];

void init(int u, int l, int r) {
  if (r - l == 1) {
    t[u] = mp(b[l], l);
    return;
  }
  int m = (l + r + 1) / 2;
  init(u * 2, l, m);
  init(u * 2 + 1, m, r);
  t[u] = max(t[u * 2], t[u * 2 + 1]);
}

pi getMax(int u, int l, int r, int x, int y) {
  if (y <= l || r <= x) {
    return mp(0, 0);
  }
  if (x <= l && r <= y) {
    return t[u];
  }
  int m = (l + r + 1) / 2;
  return max(getMax(u * 2, l, m, x, y), getMax(u * 2 + 1, m, r, x, y));
}

ll calc(int l, int r) {
  if (r <= l) {
    return 0LL;
  }
  pi pa = getMax(1, 0, n, l, r);
  int m = pa.s;
  ll res = 1LL * pa.f * (m - l + 1) * (r - m);
  res += calc(l, m);
  res += calc(m + 1, r);
  return res;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    b[i] = abs(a[i] - a[i - 1]);
  }
  init(1, 0, n);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    cout << calc(l, r) << "\n";
  }
  return 0;
}
