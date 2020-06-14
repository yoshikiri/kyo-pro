#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  set<int> a;
  vector<int> cnt(1000005);
  rep(i, n) {
    int x;
    cin >> x;
    a.insert(x);
    ++cnt[x];
  }

  vector<int> f(1000005, 0);
  for (int i = 1; i <= 1e6; ++i) {
    if (a.find(i) == a.end()) continue;
    if (f[i] == 0) {
      for (int j = 2 * i; j <= 1e6; j += i) {
        f[j] = 1;
      }
    }
  }

  int ans = 0;
  for (auto u : a) {
    if (f[u] == 0) {
      if (cnt[u] == 1) ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
