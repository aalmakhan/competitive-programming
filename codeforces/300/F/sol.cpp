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
int f[222222];
pi a[222222];
ll res[2222222];

void add(int x) {
  while (x <= n) {
    f[x]++;
    x = (x | (x + 1));
  }
}

int sum(int x) {
  int res = 0;
  while (x > 0) {
    res += f[x];
    x = (x&(x+1)) - 1;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].f);
    a[i].s = i + 1;
  }
  sort(a, a + n);

  for (int i = 0; i < n; ) {
    int j = i + 1;
    while (j < n && a[j].f == a[i].f) {
      ++j;
    }
    for (int k = i; k < j; k++) {
      int v = a[k].s;
      for (int t = 1; t <= n - 1; t++) {
        int L = t * (v - 1) + 2;
        int R = t * v + 1;
        if (L > n) {
          break;
        }
        R = min(R, n);
        res[t] += sum(R) - sum(L - 1);
      }
    }
    for (int k = i; k < j; k++) {
      add(a[k].s);
    }
    i = j;
  }
  for (int k = 1; k <= n - 1; k++) {
    if (k > 1) {
      putchar(' ');
    }
    printf(I64d, res[k]);
  }
  puts("");
  return 0;
}
