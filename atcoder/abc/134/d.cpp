#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  rep(i, n) cin >> a[i + 1];

  vector<int> ans(n + 1);
  int cnt = 0;
  for (int i = n; i >= 1; --i) {
    int sum = 0;
    for (int j = i * 2; j <= n; j += i) {
      sum += ans[j];
    }
    // ans[i] = a[i] ^ sum;
    // ans[i] = a[i] xor (sum % 2);
    if (sum % 2 == a[i])
      ans[i] = 0;
    else {
      ans[i] = 1;
      ++cnt;
    }
  }

  cout << cnt << endl;
  for (int i = 1; i <= n; ++i)
    if (ans[i]) printf("%d%c", i, (i == n) ? '\n' : ' ');
  return 0;
}
