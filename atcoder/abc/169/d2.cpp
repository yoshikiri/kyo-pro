#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<P> v;
  for (ll i = 2; i * i <= n; ++i) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    if (cnt) v.push_back({i, cnt});
  }
  if (n != 1) v.push_back({n, 1});

  int ans = 0;
  for (auto p : v) {
    int s = p.second;
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= s; ++i) {
      if (sum + i > s) break;
      sum += i;
      ++cnt;
    }
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}
