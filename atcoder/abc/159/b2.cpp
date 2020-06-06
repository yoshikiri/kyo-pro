#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool isPalindrome(string s) {
  int n = s.size();
  bool res = true;
  rep(i, n) {
    if (s[i] != s[n - i - 1]) res = false;
  }

  string t = s;
  reverse(t.begin(), t.end());
  return t == s;
  return res;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();

  bool ans = isPalindrome(s.substr(0, n / 2)) &&
             isPalindrome(s.substr(n / 2 + 1, n / 2)) && isPalindrome(s);
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
