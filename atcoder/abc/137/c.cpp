#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  map<string, int> mp;

  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++mp[s];
  }

  ll ans = 0;
  for (auto &p : mp) {
    int c = p.second;
    ans += (ll)c * (c - 1) / 2;
  }

  cout << ans << endl;

  return 0;
}
