#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  string ans;
  if (s == "Sunny") ans = "Cloudy";
  if (s == "Cloudy") ans = "Rainy";
  if (s == "Rainy") ans = "Sunny";
  cout << ans << endl;
  return 0;
}
