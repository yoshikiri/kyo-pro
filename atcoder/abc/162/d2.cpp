#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  string s;
  cin >> n >> s;

  int r = 0, g = 0, b = 0;
  rep(i, n) {
    if (s[i] == 'R') ++r;
    if (s[i] == 'G') ++g;
    if (s[i] == 'B') ++b;
  }

  ll ans = (ll)r * (ll)g * (ll)b;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int k = 2 * j - i;
      if (k >= n) continue;
      if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) --ans;
    }
  }

  cout << ans << '\n';
  return 0;
}
