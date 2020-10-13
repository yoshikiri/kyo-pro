#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, l;
  cin >> n >> l;
  int a[n];
  rep(i, n) a[i] = l + i;
  int sum = 0, ans = 1e9;
  rep(i, n) sum += a[i];
  rep(i, n) {
    int t = sum - a[i];
    if (abs(sum - t) < abs(sum - ans)) ans = t;
  }
  cout << ans << endl;
  return 0;
}
