#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> s(n, 0);
  rep(i, k){
    int d;
    cin >> d;
    rep(j, d){
      int a; cin >> a;
      --a;
      ++s[a];
    }
  }
  
  int ans = 0;
  rep(i, n) if(s[i] == 0) ++ans;
  cout << ans << endl;
  return 0;
}
