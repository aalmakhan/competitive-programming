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
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

vector<int> wx[1111111], wy[1111111];
int n, h, w;
int a[555555], b[555555];
char s[555555];
const int mod = int(1e9) + 7;

int Find(vector<int> w[], int i, int d) {
  i += n;
  int res = upper_bound(w[i].begin(), w[i].end(), d) - w[i].begin();
  if (res < w[i].size()) {
    return w[i][res];
  } else {
    return n + 1;
  }
}

int main() {
  scanf("%d%d%d", &n, &h, &w);
  scanf("%s", &s);
  
  int minx = 0, miny = 0, maxx = 0, maxy = 0;
  int x = 0, y = 0;
  wx[n].pb(0);
  wy[n].pb(0);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      ++x;
    } else if (s[i] == 'U') {
      --x;
    } else if (s[i] == 'L') {
      --y;
    } else if (s[i] == 'R') {
      ++y;
    } 
    wx[x + n].pb(i + 1);
    wy[y + n].pb(i + 1);
    a[i + 1] = x, b[i + 1] = y;

    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }

  if (1 - minx <= h - maxx && 1 - miny <= w - maxy && x == 0 && y == 0) { 
    puts("-1");
    return 0;
  }

  int lx = 1, rx = h;
  int ly = 1, ry = w;

  int p = 0, res = 0;
  x = 0, y = 0;
  while (lx <= rx && ly <= ry) {
      int np = n + 1;  
      np = min(Find(wx, -lx, p), np);
      np = min(Find(wx, h - rx + 1, p), np);
      np = min(Find(wy, -ly, p), np);
      np = min(Find(wy, w - ry + 1, p), np);
      //printf("%d %d %d %d\n", lx, ly, rx, ry);

      if (np <= n) {
        int cur = (1LL * (rx - lx + 1) * (ry - ly + 1)) % mod;
        cur = (1LL * cur * (np - p)) % mod;
        res = (res + cur) % mod;
        p = np;
        x = a[p], y = b[p];
        if (rx + x > h) --rx;
        if (lx + x < 1) ++lx;
        if (ry + y > w) --ry;
        if (ly + y < 1) ++ly;


      } else {
        int cur = (1LL * (rx - lx + 1) * (ry - ly + 1)) % mod;
        cur = (1LL * cur * (n - p)) % mod;
        res = (res + cur) % mod;

        lx += a[n];
        rx += a[n];
        ly += b[n];
        ry += b[n];

        if (lx < 1) lx = 1;
        if (rx > h) rx = h;
        if (ly < 1) ly = 1;
        if (ry > w) ry = w;

        x = 0, y = 0, p = 0;
        continue;
      }
  }
  printf("%d\n", res);
  return 0;
}
