#include <bits/stdc++.h>

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
    ++mp[s];
  }

  for (auto s : {"AC", "WA", "TLE", "RE"}) {
    cout << s << " x " << mp[s] << endl;
  }

  // cout << "AC x " << mp["AC"] << endl;
  // cout << "WA x " << mp["WA"] << endl;
  // cout << "TLE x " << mp["TLE"] << endl;
  // cout << "RE x " << mp["RE"] << endl;
  return 0;
}
