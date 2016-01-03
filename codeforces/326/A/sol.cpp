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

const int maxn = int(1e6);
int cnt[maxn + 5];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  int res = 0;
  int cur = 0;
  for (int i = 0; i <= maxn; i++) {
    cur += cnt[i];
    res += (cur&1);
    cur >>= 1;
  }
  res += __builtin_popcount(cur);
  cout << res << endl;
  return 0;
}
