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

int n, m;
pii e[111111];
pi res[111111];

void imp() {
  puts("-1");
  exit(0);
}

int main() {
  scanf("%d%d", &n, &m); 
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[i].f = mp(a, -b);
    e[i].s = i;
  }
  sort(e, e + m);

  int in = 1;
  int out = 1;
  int to = 1;
  for (int i = 0; i < m; i++) {
    int num = e[i].s;
    int part = e[i].f.s;
    if (part == 0) { 
      if (to >= in) {
        in++;
        to = 1;
      }
      if (in >= out) {
        imp();
      }
      res[num] = mp(to, in);
      ++to;
    } else {
      res[num] = mp(0, out);
      out++;
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", res[i].f + 1, res[i].s + 1);
  }
  return 0;
}
