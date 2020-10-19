#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  vector<int> b(n);

  for (int i = n; i >= 1; --i) {
    int sum = 0;
    for (int j = 2 * i; j <= n; j += i) sum += b[j - 1];
    if (sum % 2 == a[i - 1])
      b[i - 1] = 0;
    else
      b[i - 1] = 1;
  }

  int cnt = 0;
  rep(i, n) cnt += b[i];
  cout << cnt << endl;
  rep(i, n) if (b[i]) cout << i + 1 << endl;
  return 0;
}
