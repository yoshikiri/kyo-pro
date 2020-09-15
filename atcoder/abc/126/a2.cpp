#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  s[k - 1] = s[k - 1] + ('a' - 'A');
  cout << s << endl;
  return 0;
}
