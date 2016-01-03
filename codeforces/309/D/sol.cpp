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

int n, m, k;
bool bad[111111], ibad[111111];
int a[111111], b[111111], ia[111111], ib[111111];
vector<int> e[111111];
pi res;


bool cmp(const pi &a, const pi &b) {
  return 1LL * a.f * b.s < 1LL * a.s * b.f;
}

bool equal(pi a, pi b) {
  return 1LL * a.f * b.s == 1LL * a.s * b.f;
}

void die() {
  //printf("%d/%d\n", res.f, res.s);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += !bad[i];
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    if (!bad[i]) {
      printf("%d ", i + 1);
    }
  }
  puts("");
  exit(0);
}
struct CMP {
  bool operator()(const pii &a, const pii &b)  const {
    return cmp(a.f, b.f);
  }
};

bool ok(double x) {
  for (int i = 0; i < n; i++) {
    a[i] = ia[i];
    b[i] = ib[i];
    bad[i] = ibad[i];
  }
  set<pii, CMP> S;
  for (int i = 0; i < n; i++) if (!bad[i]) {
    S.insert(mp(mp(a[i], b[i]), i));
  }
  while (!S.empty()) {
    __typeof(S.begin()) it = S.begin();
    int u = (*it).s;
    pi cur = (*it).f;
    if (1.0 * cur.f >= cur.s * x) {
      return true;
    }
    bad[u] = true;
    S.erase(it);
    forit (it, e[u]) {
      int v = *it;
      if (!bad[v]) {
        S.erase(mp(mp(a[v], b[v]), v));
        --a[v];
        S.insert(mp(mp(a[v], b[v]), v));
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int u;
    scanf("%d", &u);
    --u;
    ibad[u] = true;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    e[u].pb(v);
    e[v].pb(u);
  }
  for (int i = 0; i < n; i++) {
    forit (it, e[i]) {
      if (!ibad[*it]) {
        ++ia[i];
      }
      ++ib[i];
    }
  }

  double l = 0.0, r = 1.0;
  for (int iter = 0; iter < 30; ++iter) {
    double mid = (l + r) / 2.0;
    if (ok(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  ok(l);
  die();
  return 0;
}
