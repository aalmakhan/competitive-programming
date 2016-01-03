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

pi a[222222];
int mx[222222], mn[222222], n, ans[222222];

int add(int p) {
  int l = p, r = p;
  if (l > 0 && mn[l - 1] != -1) {
    l = mn[l - 1];
  }
  if (r < n - 1 && mx[r + 1] != -1) {
    r = mx[r + 1];
  }
  mn[r] = l;
  mx[l] = r;
  return r - l + 1;
}

int main() {
  scanf("%d", &n);
  memset(mn, -1, sizeof(mn));
  memset(mx, -1, sizeof(mx));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].f);
    a[i].s = i;
  }
  sort(a, a + n, greater<pi>());
  int prev = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i].f, pos = a[i].s;
    int cur = add(pos);
    if (cur > prev) {
      for (int k = prev + 1; k <= cur; ++k) {
        ans[k] = x;
      }
      prev = cur;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
