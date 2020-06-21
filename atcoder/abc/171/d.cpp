#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  ll sum = 0;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
    ++mp[a];
  }

  int q;
  cin >> q;
  rep(nq, q) {
    int b, c;
    cin >> b >> c;
    sum += (c - b) * mp[b];
    printf("%lld\n", sum);
    mp[c] += mp[b];
    mp[b] = 0;
  }

  return 0;
}
