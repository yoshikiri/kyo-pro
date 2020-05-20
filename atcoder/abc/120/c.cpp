#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  int n = s.length();

  stack<char> t;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (t.empty()) {
      t.push(s[i]);
      continue;
    }

    int l = t.top();
    if (s[i] != l) {
      t.pop();
      ans += 2;
    } else
      t.push(s[i]);
  }

  cout << ans << '\n';
  return 0;
}
