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

const int maxn = 500000;
ll res;
int n, q, ff, cnt[555555], cur[555555];
int NEXT[5555555], d[5555555], first[555555];
int a[555555];

inline void rec(int i, int p, int m, int diff) {
  if (i == 0) {
    if (diff == -1) {
      --cnt[p];
    }
    //printf("%d ", p);
    res += cnt[p] * m;
    if (diff == 1) {
      ++cnt[p];
    }
    return;
  }
  rec(NEXT[i], p, m, diff);
  rec(NEXT[i], p * d[i], -m, diff);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= maxn; i++) if (first[i] == 0) {
    for (int j = i; j <= maxn; j += i) {
      ++ff;
      d[ff] = i;
      NEXT[ff] = first[j];
      first[j] = ff;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  while (q--) {
    int x;
    scanf("%d", &x);
    rec(first[a[x]], 1, cur[x] ? -1 : 1, cur[x] ? -1 : 1);
    //puts("");
    cur[x] ^= 1;
    printf(I64d"\n", res);
  }
  return 0;
}
