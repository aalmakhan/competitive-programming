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
int n;

vector <int> out;
vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;
vector<int> e;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs1 (to);
	}
	order.push_back (v);
}

void dfs2 (int v, int cl) {
	comp[v] = cl;
	for (size_t i=0; i<gt[v].size(); ++i) {
		int to = gt[v][i];
		if (comp[to] == -1)
			dfs2 (to, cl);
	}
}

bool sat2(int n) {
  //reading 

	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);

	comp.assign (n, -1);
	for (int i=0, j=0; i<n; ++i) {
		int v = order[n-i-1];
		if (comp[v] == -1)
			dfs2 (v, j++);
	}

	for (int i=0; i<n; ++i)
		if (comp[i] == comp[i^1]) {
			puts ("NO SOLUTION");
			return 0;
		}
	for (int i=0; i<n; ++i) {
		int ans = comp[i] > comp[i^1] ? i : i^1;
    if (i == ans) {
      out.pb(i / 2);
    }
	}
}

int n, m;
vector <map <int, vi> > e[55555];
int c[55555], t[55555];

void imp() {
  puts("No");
  exit(0);
}

void add(vi& v, int x) {
  v.pb(x);
  if (v.size() > 2) imp();
}

void add_edge(int u, int v) {
  u *= 2, v *= 2;
  g[v^1].pb(u);
  g[u^1].pb(v);
}

bool ok(int gran) {
  for (int i = 0; i < m * 2; ++i) {
    g[i].clear();
  }
 for (int u = 0; u < n; u++) {
   if (e[u].size() == 2) {
     int x = e[u][0], y = e[u][1];
     if (t[x] > t[y]) swap(x, y);
     if (t[x] > gran) return false;
     if (t[y] > gran) {
       add_edge(x, x);
     } else { 
       add_edge(x, y);
     }
   }
 } 
 out.clear();
 return sat2(m * 2);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d%d%d", &u, &v, &c[i], &t[i]);
    --u, --v;
    add(e[u][c[i]], i);
    add(e[v][c[i]], i);
  }

  int inf = int(1e9 + 5);
  int l = -1, r = inf;
  while (r - l > 1) {
    int mid = (l + r ) / 2;
    if (ok(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return 0;
}
