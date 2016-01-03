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

int n, m, d[444];
queue<int> q;
bool a[444][444];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    a[x][y] = a[y][x] = true;
  }
  if (a[0][n - 1]) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = !a[i][j];
      }
    }
  }

  memset(d, -1, sizeof(d));
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) if (a[u][v] && d[v] == -1) {
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  printf("%d\n", d[n - 1]);
  return 0;
}
