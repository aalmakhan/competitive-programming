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

int dim[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string of, name;
int x;

int main() {
  cin >> x >> of >> name;
  int res = 0;
  if (name == "month") {
    for (int i = 0; i < 12; i++) {
      res += (x <= dim[i]);
    }
  } else {
    int cur = 5;
    for (int i = 0; i < 12; i++) {
      for (int d = 1; d <= dim[i]; ++d) {
        res += (cur == x);
        ++cur;
        if (cur == 8) {
          cur = 1;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
