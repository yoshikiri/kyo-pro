#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

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

  int mx = 0;
  for (auto p : mp) {
    mx = max(mx, p.second);
  }

  vector<string> ans;
  for (auto p : mp) {
    if (p.second == mx) {
      ans.push_back(p.first);
    }
  }

  sort(ans.begin(), ans.end());
  for (auto s : ans) {
    cout << s << endl;
  }

  return 0;
}
