#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];

  int ng = 0, ok = 1e9 + 1;
  while (ok - ng > 1) {
    int m = (ok + ng) / 2;
    int cnt = 0;
    rep(i, n) { cnt += (a[i] + m - 1) / m - 1; }
    if (cnt <= k)
      ok = m;
    else
      ng = m;
  }
  cout << ok << endl;
  return 0;
}
