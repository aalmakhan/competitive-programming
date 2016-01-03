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

char s[55][55];
bool ok[111][111];
int n, bs;

void imp() {
  puts("NO");
  exit(0);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  bs = n - 1;
  memset(ok, 1, sizeof(ok));
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) if (s[a][b] == 'o') {
      for (int c = 0; c < n; c++) {
        for (int d = 0; d < n; d++) if (s[c][d] == '.') {
          int x = c - a;
          int y = d - b;
          ok[x + bs][y + bs] = false;
        }
      }
    }
  }

      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) if (s[x][y] == 'x') {
          bool flag = false;
          for (int dx = -bs; dx <= bs; dx++) {
            for (int dy = -bs; dy <= bs; dy++) if (ok[dx + bs][dy + bs]) {
              int xx = x - dx;
              int yy = y - dy;
              if (xx >= 0 && yy >= 0 && xx < n && yy < n) {
                if (s[xx][yy] == 'o') {
                  flag = true;
                  break;
                }
              }
            }
          }
          if (!flag) {
            imp();
          }
        }
      }
  puts("YES");
  for (int dx = -bs; dx <= bs; dx++) {
    for (int dy = -bs; dy <= bs; dy++) {
      if (dx == 0 && dy == 0) {
        putchar('o');
      } else {
        putchar(ok[dx + bs][dy + bs] ? 'x' : '.');
      }
    }
    puts("");
  }
  return 0;
}
