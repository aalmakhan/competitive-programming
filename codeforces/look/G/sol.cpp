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

int a[222222];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    a[i] -= i;
  }
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) {
    a[i] += i;
    if (a[i] < 0 || (i > 0 && a[i] > a[i - 1])) {
      puts(":(");
      return 0;
    }
  }
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", a[i]);
  }
  puts("");
  return 0;
}
