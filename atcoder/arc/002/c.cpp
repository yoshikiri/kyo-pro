#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

string replaceZ(string s, string x) {
  int n = s.size();
  rep(i, n - 1) {
    if ("" + s[i] + s[i + 1] == x)
      s[i] = s[i + 1] = 'Z';
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  char bs[] = {'A', 'B', 'X', 'Y'};
  vector<string> cs;
  for (auto p : bs)
    for (auto q : bs)
      cs.push_back(string(1, p) + string(1, q));

  int ans = n;
  for (auto l : cs) {
    for (auto r : cs) {
      if (l == r)
        continue;

      vector<int> dp(n + 1, n);
      dp[0] = 0;
      dp[1] = 1;
      for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (s.substr(i - 2, 2) == l || s.substr(i - 2, 2) == r)
          dp[i] = min(dp[i], dp[i - 2] + 1);
      }
      ans = min(ans, dp.back());
    }
  }
  cout << ans << endl;
  return 0;
}
