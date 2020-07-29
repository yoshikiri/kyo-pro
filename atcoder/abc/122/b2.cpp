#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  set<char> a{'A', 'C', 'G', 'T'};

  int n = s.size();
  int ans = 0;
  rep(i, n) {
    int now = 0;
    for (int j = i; j < n; ++j) {
      if (a.find(s[j]) == a.end()) break;
      ++now;
    }
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
