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

int len(ll x) {
  int res = 0;
  while (x > 0) {
    ++res;
    x >>= 1;
  }
  return max(1, res);
}

int main() {
  ll a, b;
  cin >> a >> b;
  int l1 = len(a),  l2 = len(b);

  int res = 0;
  for (int k = l1; k <= l2; k++) {
    ll x = (1LL<<k) - 1;
    for (int i = 0; i < k - 1; i++) {
      ll cur = (x^(1LL<<i));
      if (a <= cur && cur <= b) {
        ++res;
      }
    }
  }

  printf("%d\n", res);
  return 0;
}
