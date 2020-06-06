#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  map<int, int> x, y;
  rep(i, n){
    int a; cin >> a;
    ++x[i + 1 + a];
    ++y[i + 1 - a];
  }

  ll ans = 0;
  for(auto p: x){
    ans += (ll)p.second * y[p.first];
  }

  cout << ans << endl;
  return 0;
}
