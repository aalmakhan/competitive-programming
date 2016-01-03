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

string t = "CODEFORCES";

void ok() {
  puts("YES");
  exit(0);
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i <= n; i++) {
    if (i == m) {
      ok();
    }
    bool flag = true;
    int pos = i;
    for (int j = n - (m - i); j < n; j++, pos++) {
      if (j < i || s[j] != t[pos]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ok();
    }
    if (i == n) break;
    if (s[i] != t[i]) {
      break;
    }
    //printf("i=%d\n", i);

  }
  puts("NO");
  return 0;
}
