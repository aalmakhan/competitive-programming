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

char s[111][111];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      bool f = 0, a = 0, c = 0, e = 0;
      for (int x = i; x < i + 2; x++) {
        for (int y = j; y < j + 2; y++) {
          f = f || (s[x][y] == 'f');
          a = a || (s[x][y] == 'a');
          c = c || (s[x][y] == 'c');
          e = e || (s[x][y] == 'e');
        }
      }
      res += (f && a && c && e);
    }
  }
  printf("%d\n", res);
  return 0;
}
