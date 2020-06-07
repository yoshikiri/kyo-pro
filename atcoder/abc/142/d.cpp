#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll g = gcd(a, b);
  vector<pair<ll, int>> fact;
  for (ll i = 2; i * i <= g; ++i) {
    int cnt = 0;
    while (g % i == 0) {
      g /= i;
      ++cnt;
    }
    if (cnt != 0) fact.push_back({i, cnt});
  }
  if (g != 1) fact.push_back({g, 1});

  int ans = 1;
  ans += fact.size();
  cout << ans << endl;
  return 0;
}
