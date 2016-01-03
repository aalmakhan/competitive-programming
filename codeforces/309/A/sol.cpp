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
int k, a[1111], n;
int c[1111][1111];

int main() {
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    n += a[i];
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  int res = 1;
  int cur = 0;
  for (int i = 0; i < k; i++) {
    res = 1LL * res * c[cur + a[i] - 1][a[i] - 1] % mod;
    cur += a[i];
  }
  cout << res << endl;
  return 0;
}
