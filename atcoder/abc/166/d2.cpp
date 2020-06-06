#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  cin >> x;

  // vector<P> f;
  // for(ll i=2;i*i<=x;++i){
  //   int cnt = 0;
  //   while(x%i == 0){
  //     x /= i;
  //     ++cnt;
  //   }
  //   if(cnt==0) continue;
  //   f.push_back({i, cnt});
  // }
  // if(x != 1) f.push_back({x, 1});

  for(ll i=-1000;i<=1000;++i){
    ll a = 1;
    rep(j, 5) a *= i;
    ll res = a - x;
    for(ll j=-1000;j<=1000;++j){
      ll b = 1;
      rep(k, 5) b *= j;
      if(b == res) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
