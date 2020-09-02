#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll a;
  char s[4];
  cin >> a;
  rep(i, 4) cin >> s[i];

  int b = (s[0] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
  cout << (a * b) / 100 << endl;

  return 0;
}
