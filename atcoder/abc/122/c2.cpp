#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> a(n + 1);
  for (int i = 1; i < n; ++i) {
    a[i + 1] = a[i];
    if (s[i] == 'C' && s[i - 1] == 'A') ++a[i + 1];
  }

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    int ans = a[r] - a[l];
    // if (l >= 2 && s[l - 1] == 'C' && s[l - 2] == 'A') --ans;
    cout << ans << endl;
  }
  return 0;
}
