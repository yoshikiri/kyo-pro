#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pos, neg;
  rep(i, n) {
    cin >> a[i];
    if (a[i] < 0)
      neg.push_back(a[i]);
    else
      pos.push_back(a[i]);
  }

  int P = pos.size(), N = neg.size();
  bool ok = false;
  if (P > 0) {
    if (n == k)
      ok = (N % 2 == 0);
    else
      ok = true;
  } else {
    ok = (k % 2 == 0);
  }

  mint ans = 1;
  if (!ok) {
    sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
    rep(i, k) { ans *= a[i]; }
  } else {
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());

    if (k % 2 == 1) {
      ans *= pos.back();
      pos.pop_back();
    }

    vector<ll> p;
    while (pos.size() >= 2) {
      ll x = pos.back();
      pos.pop_back();
      x *= pos.back();
      pos.pop_back();
      p.push_back(x);
    }
    while (neg.size() >= 2) {
      ll x = neg.back();
      neg.pop_back();
      x *= neg.back();
      neg.pop_back();
      p.push_back(x);
    }
    sort(p.rbegin(), p.rend());
    rep(i, k / 2) {
      ans *= p[i];
      cout << ans << endl;
      // ans = ans * p[i] % mod;
      // ans = (ans + mod) % mod;
    }
  }

  cout << ans << endl;

  return 0;
}
