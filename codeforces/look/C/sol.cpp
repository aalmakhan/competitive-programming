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

int odd, even;
int n, k;

void winOdd() {
  puts("Stannis");
  exit(0);
}

void winEven() {
  puts("Daenerys");
  exit(0);
}

void check(int n, int k, int odd, int even) {
  int m = n - k;
  int m1 = (m + 1) / 2;
  int m2 = m - m1;
  if (m2 >= even && odd % 2 != (m - even) % 2) {
    winOdd();
  }
  if (m1 >= odd || (m1 >= even && odd % 2 == (m - even) % 2)) {
    return;
  }
  winOdd();
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x&1) {
      odd++;
    } else {
      even++;
    }
  }
  int m = n - k;
  int m1 = (m + 1) / 2;
  int m2 = m - m1;
  if (m1 >= even && odd % 2 != (m - even) % 2) {
    winOdd();
  }
  if (m2 >= odd || (m2 >= even && odd % 2 == (m - even) % 2)) {
    winEven();
  }
  if (m % 2 == 0) {
    winEven();
  }

  check(n - 1, k, odd - 1, even);
  check(n - 1, k, odd, even - 1);
  winEven();
  return 0;
}
