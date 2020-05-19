#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> num(n, -1);

  bool ok = true;

  rep(i, m) {
    int s, c;
    cin >> s >> c;
    --s;
    if (num[s] == -1) {
      num[s] = c;
      if (s == 0 && c == 0 && n != 1) ok = false;
    } else {
      if (num[s] != c) ok = false;
    }
  }

  // for (auto v : num) {
  //   cout << v;
  // }
  // cout << '\n';

  // if (num[0] == 0 && n != 1) {
  //   ok = false;
  // }

  if (!ok) {
    cout << -1 << '\n';
    return 0;
  }

  string ans;
  rep(i, n) {
    if (num[i] == -1) {
      if (i == 0 && n != 1)
        ans += '1';
      else if (i == 0 && n == 1) {
        ans += '0';
      } else
        ans += '0';
    } else
      ans += num[i] + '0';
  }

  // while (ans[0] == '0' && ans.length() > 1) {
  //   ans = ans.substr(1, ans.length());
  // }

  if (ans.length() == n)
    cout << ans << '\n';
  else
    cout << -1 << '\n';

  return 0;
}
