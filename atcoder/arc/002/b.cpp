#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool check(int y) {
  bool ok = false;
  if (y % 400 == 0)
    ok = true;
  else if (y % 100 == 0)
    ok = false;
  else if (y % 4 == 0)
    ok = true;
  else
    ok = false;
  return ok;
}

int main() {
  string s;
  cin >> s;
  int Y = atoi(s.substr(0, 4).c_str());
  int M = atoi(s.substr(5, 2).c_str());
  int D = atoi(s.substr(8, 2).c_str());
  // cout << Y << m << d;
  set<int> sm;
  sm.insert(1);
  sm.insert(3);
  sm.insert(5);
  sm.insert(7);
  sm.insert(8);
  sm.insert(10);
  sm.insert(12);

  for (int y = Y; y < 10000; ++y) {
    int fm = (y == Y ? M : 1);
    for (int m = fm; m <= 12; ++m) {
      int fd = (m == M ? D : 1);
      int ld = 30;
      if (sm.find(m) != sm.end())
        ld = 31;
      else if (m == 2) {
        if (check(y))
          ld = 29;
        else
          ld = 28;
      }
      for (int d = fd; d <= ld; ++d) {
        if (y % (m * d) == 0) {
          printf("%4d/%02d/%02d\n", y, m, d);
          return 0;
        }
      }
    }
  }
  return 0;
}
