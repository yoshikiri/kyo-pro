#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  vector<int> id(m, -1);
  vector<int> a;
  int len = 0;
  ll sum = 0;
  while (id[x] == -1) {
    id[x] = len;
    ++len;
    a.push_back(x);
    sum += x;
    x = x * x % m;
  }

  int c = len - id[x];
  ll s = 0;
  for (int i = id[x]; i < len; ++i) s += a[i];

  ll ans = 0;
  if (n <= len) {
    rep(i, n) ans += a[i];
  } else {
    ans += sum;
    n -= len;
    ans += s * (n / c);
    n %= c;
    rep(i, n) ans += a[id[x] + i];
  }
  cout << ans << endl;

  return 0;
}
