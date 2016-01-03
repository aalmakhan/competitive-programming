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


bool cmp(pi a, pi b) {
  return 1LL * a.f * b.s < 1LL * a.s * b.f;
}

bool equal(pi a, pi b) {
  return 1LL * a.f * b.s == 1LL * a.s * b.f;
}

struct CMP {
  bool operator()(const pii &a, const pii &b)  const {
    return 1LL * a.f.f * b.f.s < 1LL * a.f.s * b.f.f;
  }
};

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
  assert(cnt > 0);
  puts("");
  exit(0);
}
void calc(int print) {
  for (int i = 0; i < n; i++) {
    a[i] = ia[i];
    b[i] = ib[i];
    //printf("%d %d\n", a[i], b[i]);
    bad[i] = ibad[i];
  }
  set<pii, CMP> S;
  S.clear();
  for (int i = 0; i < n; i++) if (!bad[i]) {
    S.insert(mp(mp(a[i], b[i]), i));
  }
  while (!S.empty()) {
    __typeof(S.begin()) it = S.begin();
    int u = (*it).s;
    pi cur = (*it).f;
    //printf("u=%d    %d/%d\n", u + 1, cur.f, cur.s);
    if (print && equal(res, cur)) {
      die();
    }
    if (!print && cmp(res, cur)) {
      res = cur;
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
  res = mp(0, 1);
  calc(0);
  calc(1);
  return 0;
}
