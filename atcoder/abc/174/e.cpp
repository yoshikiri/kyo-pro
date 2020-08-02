#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ng = 0, ok = 1e9;
  while (ok - ng > 1) {
    int m = (ok + ng) / 2;
    auto f = [&](int x) {
      ll now = 0;
      rep(i, n) now += (a[i] - 1) / x;
      return now <= k;
    };

    if (f(m))
      ok = m;
    else
      ng = m;
  }

  cout << ok << endl;
  return 0;
}
