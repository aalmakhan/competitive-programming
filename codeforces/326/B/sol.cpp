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

const int mod = int(1e9) + 7;
int n, k, f[1111111];
ll l;
int a[1111111], p[1111111];

bool cmp(int i, int j) {
  return a[i] < a[j];
}

int main() {
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    p[i] = i;
  }
  sort(p, p + n, cmp);

  for (int i = 0; i < n; i++) {
    f[i] = 1;
  }

  ll res = 0;
  ll bn = (l - 1) / n;
  for (int j = 1; j <= k; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      int lst = i + 1;
      while (lst < n && a[p[lst]] == a[p[i]]) {
        ++lst;
      }
      for (int tmp = i; tmp < lst; ++tmp) {
        int ind = p[tmp];
        cur += f[ind];
        if (cur >= mod) cur -= mod;
      }
      while (i < lst) {
        int ind = p[i];
        if (bn + 1 >= j) {
          ll occ = bn + 1 - j;
          if (bn * n + ind < l) {
            ++occ;
          }
          if (occ > 0) {
            occ %= mod;
            res = (res + occ * f[ind]) % mod;
          }
        }
        f[ind] = cur;
        ++i;
      }
      i = lst - 1;
    }
  }

  cout << res << endl;
  return 0;
}
