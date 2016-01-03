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

int n, p, q, an;
pi a[111111];

ll area(pi a, pi b) {
  return 1LL * a.f * b.s - 1LL * a.s * b.f;
}

ll area(pi a, pi b, pi c) {
  return 1LL * (b.f - a.f) * (c.s - a.s) - 1LL * (b.s - a.s) * (c.f - a.f);
}

int main() {
  scanf("%d%d%d", &n, &p, &q);
  int mx = 0, my = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].f, &a[i].s);
    mx = max(mx, a[i].f);
    my = max(my, a[i].s);
  }
  a[n++] = mp(0, my);
  sort(a, a + n);
  an = 0;
  for (int i = 0; i < n; i++) {
    while (an > 1 && area(a[an - 2], a[an - 1], a[i]) >= 0) {
      --an;
    }
    a[an++] = a[i];
  }
  n = an;
  a[n++] = mp(mx, 0);
  //for (int i = 0; i < n; i++) {
  //  printf("%d %d\n", a[i].f, a[i].s);
  //}
  double res = 0.0 + p + q;
  for (int i = 0; i < n - 1; i++) {
    ll s1 = area(mp(p, q), a[i]);
    ll s2 = area(mp(p, q), a[i + 1]);
    if ((s1 >= 0 && s2 <= 0) || (s1 <= 0 && s2 >= 0)) {
      //printf("(%d %d) (%d %d)\n", a[i].f, a[i].s, a[i + 1].f, a[i + 1].s);
      double X1 = a[i].f, Y1 = a[i].s;
      double X2 = a[i + 1].f, Y2 = a[i + 1].s;
      double A = X2 - X1;
      double B = Y2 - Y1;
      double t = (A * q - B * p) / (A * Y1 - B * X1);
      res = min(res, t);
    }
  }
  printf("%.10lf\n", res);
  return 0;
}
