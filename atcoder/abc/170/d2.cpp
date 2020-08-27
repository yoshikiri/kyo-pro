#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1000005;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> sieve(INF);
  for (auto x : a) {
    if (sieve[x] != 0) {
      sieve[x] = 2;
      continue;
    }
    for (int i = x; i < INF; i += x) {
      ++sieve[i];
    }
  }

  int ans = 0;
  for (auto x : a) {
    if (sieve[x] == 1) ++ans;
  }
  cout << ans << endl;
  return 0;
}
