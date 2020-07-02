#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];

  sort(d.begin(), d.end());
  int a = d[n / 2 - 1];
  int b = d[n / 2];
  int ans = b - a;
  cout << ans << endl;
  return 0;
}
