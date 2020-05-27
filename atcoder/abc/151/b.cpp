#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k, m;
  cin >> n >> k >> m;

  int sum = 0;
  rep(i, n - 1) {
    int a;
    cin >> a;
    sum += a;
  }

  int ans = m * n - sum;
  if (ans > k)
    cout << -1 << endl;
  else
    cout << max(ans, 0) << endl;
  return 0;
}
