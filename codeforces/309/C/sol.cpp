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

const int mod = int(1e9 + 7);
int n, m;
int color[111111];
vector <pi> e[111111];

bool dfs(int u, int c = 0) {
  //printf("u=%d c=%d\n", u, c);
  color[u] = c;
  forit(it, e[u]) {
    int v = (*it).f;
    int rl = (*it).s;
    //printf("u=%d v=%d\n", u, v);
    int cc = (rl == 1) ? c : 1 - c;
    if (color[v] == -1) {
      if (!dfs(v, cc)) {
        return false;
      }
    } else if (color[v] != cc) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    //printf("%d %d %d\n", x, y, z);
    e[x].pb(mp(y, z));
    e[y].pb(mp(x, z));
  }
  memset(color, -1, sizeof(color));
  int res = 1;
  for (int i = 0; i < n; i++) {
    //printf("u=%d\n", i + 1);
    if (color[i] == -1) {
      if (!dfs(i)) {
        puts("0");
        return 0;
      }
      //for (int j = 0; j < n; j++) {
      //  printf("%d ", color[j]);
      //}
      //puts("");
      if (i) {
        res = (res * 2) % mod;
      }
    }
  }
  cout << res << endl;
  return 0;
}
