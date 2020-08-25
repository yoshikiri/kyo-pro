#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T> struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}

  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }

  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }

  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
  int n, q;
  cin >> n >> q;
  int a[n];
  rep(i, n) cin >> a[i];
  vector<int> pi(n + 1, -1);
  vector<vector<int>> ps(n);
  rep(i, n) {
    int l = pi[a[i]];
    if (l != -1) ps[l].push_back(i);
    pi[a[i]] = i;
  }

  vector<vector<P>> qs(n);
  rep(qi, q) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qs[l].push_back({r, qi});
  }

  vector<int> ans(q);
  BIT<int> d(n);
  for (int x = n - 1; x >= 0; --x) {
    for (int y : ps[x]) d.add(y, 1);
    for (auto query : qs[x]) {
      int r = query.first, i = query.second;
      ans[i] = (r - x + 1) - d.sum(r);
    }
  }

  rep(i, q) cout << ans[i] << endl;
  return 0;
}
