#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int h[n];
  rep(i, n) cin >> h[i];

  vector<int> to[n];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  int ans = 0;
  rep(i, n){
    int mx = h[i];
    bool ok = true;
    for(auto v: to[i]){
      if(mx <= h[v]) ok = false;
    }
    if(ok) ++ans;
  }

  cout << ans << endl;
  return 0;
}
