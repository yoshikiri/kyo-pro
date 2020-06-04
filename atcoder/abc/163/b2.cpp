#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  int sum = 0;
  rep(i, m) {
    int a;
    cin >> a;
    sum += a;
  }

  if (sum > n) {
    cout << -1 << endl;
  } else {
    cout << n - sum << endl;
  }
  return 0;
}
