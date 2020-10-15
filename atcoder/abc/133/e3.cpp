#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    n /= 2;
    k = k * k % mod;
  }
  return res;
}

int k;
ll ans = 1;
vector<int> to[100005];

void dfs(int u, int p = -1) {
  for (auto v : to[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  int nk = ((p == -1) ? k : k - 2);
  int c = ((p == -1) ? to[u].size() + 1 : to[u].size() - 1);

  ll f = 1;
  rep(i, c) f = f * (nk - i) % mod;
  ans = ans * f % mod;
  cout << ans << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  // int mx = max(n, k);
  // vector<ll> f(mx + 1, 1);
  // rep(i, mx) f[i + 1] = f[i] * (i + 1) % mod;
  // auto p = [&](int a, int b) {
  //   if (a < b) return 0LL;
  //   return f[a] * modpow(f[a - b], mod - 2) % mod;
  // };

  dfs(0);
  cout << ans << endl;

  // vector<int> open(n);
  // open[0] = 1;
  // queue<int> q;
  // q.push(0);
  // while (!q.empty()) {
  //   int u = q.front();
  //   q.pop();
  //   int x = k - 2;
  //   int y = d[u] - 1;
  //   if (u == 0) {
  //     x = k - 1;
  //     y = d[u];
  //   }
  //   x = max(0, x);
  //   ans = ans * p(x, y) % mod;
  //   for (auto v : to[u]) {
  //     if (open[v]) continue;
  //     open[v] = 1;
  //     q.push(v);
  //   }
  // }
  // cout << ans << endl;
  return 0;
}
