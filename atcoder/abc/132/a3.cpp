#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size())++ mp[s[i]];
  for (auto p : mp) {
    if (p.second != 2) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
