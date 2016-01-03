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

int a[111111], b[111111], n, d[111111];
pi e[111111];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &e[i].f, &e[i].s);
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    a[i] = e[i].f;
    b[i] = e[i].s;
    int p = lower_bound(a, a + i, a[i] - b[i]) - a;
    d[i] = (p > 0 ? d[p - 1] : 0) + i - p;
    //printf("%d %d %d\n", a[i], b[i], d[i]);
  }
  int res = n;
  for (int i = 0; i < n; i++) {
    res = min(res, n - i - 1 + d[i]);
  }
  printf("%d\n", res);
  return 0;
}
