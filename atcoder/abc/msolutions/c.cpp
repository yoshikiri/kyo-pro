#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];

  int left = 0, right = k;
  for (int i = k + 1; i <= n; ++i) {
    cout << (a[left] < a[right] ? "Yes" : "No") << endl;
    ++left, ++right;
  }
  return 0;
}
