#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 2019;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());

  vector<int> a(n + 1);
  int mul = 1;
  rep(i, n) {
    int x = s[i] - '0';
    x = x * mul % mod;
    a[i + 1] = (a[i] + x) % mod;
    mul = mul * 10 % mod;
  }

  vector<int> cnt(mod);
  rep(i, n + 1)++ cnt[a[i]];
  ll ans = 0;
  rep(i, 2019) { ans += (ll)cnt[i] * (cnt[i] - 1) / 2; }
  cout << ans << endl;
  return 0;
}
