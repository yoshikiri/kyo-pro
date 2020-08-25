#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int r = 0;
  rep(i, n) r += (s[i] == 'R');
  string t;
  rep(i, n) {
    if (i < r)
      t += 'R';
    else
      t += 'W';
  }

  int ans = 0;
  rep(i, n) if (s[i] != t[i])++ ans;
  cout << ans / 2 << endl;

  return 0;
}
