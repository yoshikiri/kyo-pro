#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, n) cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());
  ll t = 0;
  rep(i, n) {
    t += v[i].second;
    if (t > v[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
