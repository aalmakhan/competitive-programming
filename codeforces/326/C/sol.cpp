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

const int maxa = 10;

int p[17][111111], level[111111];
vector<int> buf;
vector<int> e[111111];
vi t[17][111111];

void add(int x, vi* v) {
  if (v->size() < maxa) {
    v->pb(x);
  }
}

void Merge(const vi& a, const vi& b, vi* c) {
  c->clear();
  int i = 0, j = 0;
  while ((i < a.size() || j < b.size()) && c->size() < maxa) {
    if (i < a.size() && (j == b.size() || a[i] < b[j])) {
      c->pb(a[i++]);
    } else {
      c->pb(b[j++]);
    }
  }
}

void print(const vi& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  puts("");
}

void Merge(const vi& a, vi& c) {
  //puts("merging");
  //print(a);
  buf.clear();
  Merge(a, c, &buf);
  swap(c, buf);
}

void dfs(int u, int par = -1, int l = 0) {
  p[0][u] = par;
  level[u] = l;
  for (int k = 1; k <= 16; k++) {
    int v = p[k - 1][u];
    if (v != -1) {
      p[k][u] = p[k - 1][v];
      Merge(t[k - 1][u], t[k - 1][v], &t[k][u]);
    }
  }

  forit (it, e[u]) {
    int v = *it;
    if (v == par) continue;
    dfs(v, u, l + 1);
  }
}



void jump(int &u, int k, vi& ans) {
  //printf("jump=%d\n", u + 1);
  Merge(t[k][u], ans);
  u = p[k][u];
}

void go(int u, int v, vi& ans) {
  //printf("u=%d v=%d\n", u + 1, v + 1);
  if (level[u] < level[v]) {
    swap(u, v);
  }

  for (int k = 16; k >= 0; --k) if (p[k][u] != -1 && level[p[k][u]] >= level[v]) {
    jump(u, k, ans);
  }

  if (u == v) {
    Merge(t[0][u], ans);
    //printf("%d\n", u + 1);
    return;
  }

  for (int k = 16; k >= 0; --k) if (p[k][u] != p[k][v]) {
    jump(u, k, ans);
    jump(v, k, ans);
  }
  jump(u, 0, ans);
  jump(v, 0, ans);
  Merge(t[0][u], ans);
  //printf("%d\n", u + 1);
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= 16; k++) {
      p[k][i] = -1;
      t[k][i].reserve(maxa);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    e[u].pb(v), e[v].pb(u);
  }
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    --v;
    add(i, &t[0][v]);

  }
  //for (int v = 0; v < n; v++ ) {
  //  print(t[0][v]);
  //}
  dfs(0);
  

  buf.reserve(maxa);
  vi ans;
  ans.reserve(maxa);
  while (q--) {
    ans.clear();
    int u, v, a;
    scanf("%d%d%d", &u, &v, &a);
    --u, --v;
    go(u, v, ans);
    if (a > ans.size()) {
      a = ans.size();
    }
    printf("%d", a);
    for (int i = 0; i < a; i++) {
      printf(" %d", ans[i] + 1);
    }
    puts("");
  }
  return 0;
}
