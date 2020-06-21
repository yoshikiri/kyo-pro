#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  if (n % 2 == 1) {
    puts("No");
    return 0;
  }

  string t = s.substr(0, n / 2);
  if (t + t == s)
    puts("Yes");
  else
    puts("No");
  return 0;
}
