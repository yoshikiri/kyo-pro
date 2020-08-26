#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct SegTree {
  ll n;
  vector<ll> v;

  SegTree(int size) {
    n = 1;
    while (n < size) n *= 2;
    v = vector<ll>(2 * n - 1);
  }

  void add(int i, ll x) {
    i += n - 1;
    v[i] += x;
    while (i > 0) {
      i = (i - 1) / 2;
      v[i] = v[2 * i + 1] + v[2 * i + 2];
    }
  }

  ll query(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return v[k];
    ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return c1 + c2;
  }

  ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> w(n);
  rep(i, n) cin >> w[i].first >> w[i].second;

  sort(w.begin(), w.end());
  ll ans = 0;
  ll sum = 0;
  queue<P> q;
  rep(i, n) {
    ll x = w[i].first;
    ll h = w[i].second;
    while (!q.empty() && q.front().first < x) {
      sum -= q.front().second;
      q.pop();
    }
    h -= sum;
    if (h <= 0) continue;
    int cnt = (h + a - 1) / a;
    ans += cnt;

    ll dmg = (ll)a * cnt;
    sum += dmg;
    q.push({x + (ll)2 * d, dmg});
  }
  cout << ans << endl;
  return 0;
}