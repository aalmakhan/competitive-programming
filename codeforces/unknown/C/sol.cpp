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
map <pi, vector<int> > M;
pi a[222222];
vector <int> ans;

bool bad(int a, int b, int c, int d, int e, int f) {
  ll xx = 1LL * (b - d) * (e - c) * a * f;
  ll yy = 1LL * (d - f) * (c - a) * b * e;
  return xx > yy;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    M[mp(x, y)].pb(i);
    a[i] = mp(x, y);
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
  int an = 0;
  for (int i = 0; i < n; i++) {
    while (an > 0 && a[an - 1].s <= a[i].s) {
      --an;
    }
    a[an++] = a[i];
  }
  n = an;
  reverse(a, a + n);

  an = 0;
  for (int i = 0; i < n; i++) {
    while (an > 1 && bad(a[i].f, a[i].s, a[an - 1].f, a[an - 1].s, a[an - 2].f, a[an - 2].s)) {
      --an;
    }
    a[an++] = a[i];
  }
  n = an;

  for (int i = 0; i < n; i++) {
    forit (it, M[a[i]]) {
      ans.pb(*it);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i] + 1);
  }
  puts("");
  return 0;
}
