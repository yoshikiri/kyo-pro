#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  vector<P> s(m);
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    s[i] = {c, b};
  }
  sort(s.rbegin(), s.rend());

  int cur = 0;
  for (auto p : s) {
    int now = cur;
    for (int i = now; i < now + p.second; ++i) {
      if (a[i] < p.first) {
        a[i] = p.first;
        ++cur;
      } else
        break;
    }
  }

  ll sum = 0;
  rep(i, n) sum += a[i];
  cout << sum << endl;
  return 0;
}
