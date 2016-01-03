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

double a, b, c, d;

double gmax(double a, double b, double c, double d) {
  return max(max(a * b, a * d), max(c * b, c * d));
}

double gmin(double a, double b, double c, double d) {
  return min(min(a * b, a * d), min(c * b, c * d));
}

bool ok(double x) {
  double l1 = gmin(a - x, d - x, a + x, d + x);
  double r1 = gmax(a + x, d - x, a + x, d + x);
  double l2 = gmin(c - x, b - x, c + x, b + x);
  double r2 = gmax(c - x, b - x, c + x, b + x);
  if (r1 < l2 ||r2 < l1) return false;
  return true;
}

int main() {
  cin >> a >> b >> c >> d;
  double l = 0.0, r = 1e9;
  for (int iter = 0; iter < 200; ++iter) {
    double mid = (l + r) / 2.0;
    if (ok(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.10lf\n", r);
  return 0;
}
