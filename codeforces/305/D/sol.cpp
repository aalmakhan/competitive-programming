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
typedef pair <pi, int> pii;
typedef vector <int> vi;
typedef long long ll;

const int maxx = 200000;
int cnt1[222222], cur1[222222], cur2[222222], n, ans[222222];
pii a[222222];
int first1[222222], first2[222222], ne1[222222], ne2[222222];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ++cnt1[x], ++cnt2[y];
    a[i].f = mp(x, y);
    a[i].s = i;
  }
  random_shuffle(a, a + n);
  memset(first1, -1, sizeof(first));
  memset(first2, -1, sizeof(first2));
  for (int i = 0; i < n; i++) {
    int u = a[i].f.f, v = a[i].f.s;
    if (cur1[u] <= 0 && cur2[v] <= 0) {
      ans[i] = 1;
      ++cur1[u], ++cur2[v];
    } else if (cur1[u] >= 0 && cur2[v] >= 0) {
      ans[i] = -1;
      --cur1[u], --cur1[v];
    } else {
      if (cur1[u] == 1) {
        ++ans[i];
        cur1[u] =  1
      }
    }
    ne1[i] = first1[u], first1[u] = i;
    ne2[i] = first2[v], first2[v] = i;
  }

  return 0;
}
