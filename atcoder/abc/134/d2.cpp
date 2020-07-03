#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  rep(i, n) cin >> a[i + 1];

  vector<int> b(n + 1);
  int m = 0;
  for (int i = n; i >= 1; --i) {
    int cnt = 0;
    for (int j = 2 * i; j <= n; j += i) {
      cnt += b[j];
    }
    cnt %= 2;
    b[i] = a[i] ^ cnt;
    m += b[i];
  }

  cout << m << endl;
  rep(i, n) if (b[i + 1]) cout << i + 1 << endl;
  return 0;
}
