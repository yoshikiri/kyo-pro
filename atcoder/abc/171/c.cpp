#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;

  vector<int> d;
  while (n > 0) {
    int x = n % 26;
    if (x == 0) {
      x = 26;
      n -= 26;
    }
    d.push_back(x);
    n /= 26;
  }

  string s;
  for (auto x : d) {
    s += (x - 1) + 'a';
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
  return 0;
}
