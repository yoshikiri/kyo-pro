#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<P> d(n);
  rep(i, n) cin >> d[i].first >> d[i].second;

  int cnt = 0;
  bool ok = false;
  rep(i, n) {
    if (d[i].first == d[i].second) {
      ++cnt;
    } else {
      cnt = 0;
    }
    if (cnt >= 3) ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
