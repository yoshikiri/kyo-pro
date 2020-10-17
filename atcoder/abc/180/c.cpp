#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> ans;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i * i != n) ans.push_back(n / i);
    }
  }
  sort(ans.begin(), ans.end());
  for (auto v : ans) cout << v << endl;
  return 0;
}
