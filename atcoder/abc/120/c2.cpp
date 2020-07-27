#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int cnt = 0;
  rep(i, n) {
    if (s[i] == '0')
      ++cnt;
    else
      --cnt;
  }

  if (cnt == 0)
    cout << n << endl;
  else
    cout << n - abs(cnt) << endl;
  return 0;
}
