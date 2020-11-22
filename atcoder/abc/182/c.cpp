#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int sum = 0;
  int n = s.size();
  rep(i, n)(sum += s[i] - '0') %= 3;

  if (sum == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> cnt(3);
  rep(i, n) {
    int x = (s[i] - '0') % 3;
    ++cnt[x];
    if (x == sum) {
      cout << 1 << endl;
      return 0;
    }
  }

  if (sum == 2) {
    if (cnt[1] >= 2 && n >= 3) {
      cout << 2 << endl;
      return 0;
    }
  }
  if (sum == 1) {
    if (cnt[2] >= 2 && n >= 3) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
