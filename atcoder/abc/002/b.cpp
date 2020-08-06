#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = "";
  set<char> ng{'a', 'i', 'u', 'e', 'o'};
  rep(i, n) {
    if (ng.find(s[i]) == ng.end()) t.push_back(s[i]);
  }
  cout << t << endl;
  return 0;
}
