#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int sum = 0;
  rep(i, n) { sum = (sum + (s[i] - '0')) % 9; }
  cout << (sum == 0 ? "Yes" : "No") << endl;
  return 0;
}
