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

typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

multiset<int> S;
int n;
int a, b, c;

multiset<int>::iterator getLast() { 
  __typeof(S.begin()) it = S.end();
  --it;
  return it;
}

void RMV(int a) {
      auto it = S.upper_bound(a);
      if (it != S.begin()) {
        --it;
        //printf("plus %d\n", *it);
        S.erase(it);
      }
}

bool ok(const vector<int>& v, int k) {
  int p = v.size() - 1;
  p -= k;
  if (p < 0) return true;

  int ra = k, rb = k;
  while (p >= 0 && ra > 0 && rb > 0) {
    if (v[p] > a + b) return false;
    if (v[p] <= b) break;
    --p, --ra, --rb;
  }
  if (p < 0) return true;

  while (p >= 0 && rb > 0) {
    if (v[p] > b) return false;
    --p;
    --rb;
  }
  if (p < 0) return true;

  while (p >= 0 && ra > 0) {
    if (v[p] > a) return false;
    --p;
    --ra;
  }

  return (p < 0);
}

int main() {
  scanf("%d", &n);
  scanf("%d%d%d", &a, &b, &c);
  if (b < a) {
    swap(a, b);
  }
  if (c < b) {
    swap(b, c);
  }
  if (b < a) {
    swap(a, b);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    S.insert(x);
  }
  int res = 0;
  while (!S.empty()) {
    auto it = getLast();
    if (*it > a + b + c) {
      puts("-1");
      return 0;
    }
    if (*it <= b + c) {
      break;
    }
    //printf("a+b+c %d\n", *it);
    S.erase(it);
    ++res;
  }


  while (!S.empty()) {
    auto it = getLast();
    //cout << *it << endl;
    if (*it <= a + c) {
      break;
    }
    //printf("b+c %d\n", *it);
    S.erase(it);
    ++res;
    if (!S.empty()) {
      RMV(a);
    }
  }

  while (!S.empty()) {
    auto it = getLast();
    if (*it <= max(a + b, c)) {
      break;
    }
    //printf("a+c %d\n", *it);
    S.erase(it);
    ++res;
    if (!S.empty()) {
      RMV(b);
    }
  }

  if (a + b > c) {
    while (!S.empty()) {
      auto it = getLast();
      if (*it <= c) {
        break;
      }
      S.erase(it);
      ++res;
      if (!S.empty()) {
        RMV(c);
      }
    }
  }


  vector<int> v(S.begin(), S.end());

  int l = -1, r = v.size();
  while (r - l > 1) {
    int mid = (l + r) /2;
    if (ok(v, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%d\n", res + r);
  return 0;
}
