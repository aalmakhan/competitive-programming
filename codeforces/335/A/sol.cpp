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

int pos[111111], a[111111], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    --a[i];
    pos[a[i]] = i;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    while (j < n && pos[j] > pos[j - 1]) {
      ++j;
    }
    mx = max(mx, j - i);
    i = j - 1;
  }
  printf("%d\n", n - mx);
  return 0;
}
