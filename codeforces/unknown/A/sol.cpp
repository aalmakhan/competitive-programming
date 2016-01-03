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

int A, B, n;
int st, t, m;

bool ok(int r) {
  int l = st;
  ll s = 1LL * (r - 1) * B + A;
  if (s > t) {
    return false;
  }
  ll f = 1ll * (l - 1) * B + A;
  ll sum = (s + f) * (r - l + 1) / 2;
  if (m == 1) {
    return sum <= t;
  }
  ll need = (sum + m - 1) / m;
  if (need < s) need = s;
  return need <= t;
}

int main() {
  scanf("%d%d%d", &A, &B, &n);
  while (n--) {
    scanf("%d%d%d", &st, &t, &m);
    int l = st - 1, r = 1000001;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (ok(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (l >= st) {
      printf("%d\n", l);
    } else {
      puts("-1");
    }
  }
  return 0;
}
