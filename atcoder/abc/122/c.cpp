#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> a(n, 0);

  for (int i = 1; i < n; ++i) {
    a[i] = a[i - 1];
    if (s[i - 1] == 'A' && s[i] == 'C') ++a[i];
  }

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int ans = a[r] - a[l - 1];
    if (s[l] == 'C' && s[l - 1] == 'A') --ans;
    cout << ans << '\n';
  }
  return 0;
}
