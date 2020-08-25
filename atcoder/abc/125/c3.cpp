#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct SegmentTree {
  int n;
  vector<int> v;
  SegmentTree(int size, int *a) {
    n = 1;
    while (n < size) n *= 2;
    v = vector<int>(2 * n - 1);
    rep(i, size) v[i + n - 1] = a[i];
    rep(i, size) {
      int j = i + n - 1;
      while (j > 0) {
        j = (j - 1) / 2;
        v[j] = gcd(v[2 * j + 1], v[2 * j + 2]);
      }
    }
  }

  SegmentTree(int size) {
    n = 1;
    while (n < size) n *= 2;
    v = vector<int>(2 * n - 1, 0);
  }

  void update(int i, int x) {
    i += n - 1;
    v[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      v[i] = gcd(v[2 * i + 1], v[2 * i + 2]);
    }
  }

  int solve(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return v[k];
    int c1 = solve(a, b, 2 * k + 1, l, (l + r) / 2);
    int c2 = solve(a, b, 2 * k + 2, (l + r) / 2, r);
    return gcd(c1, c2);
  }

  int solve(int a, int b) { return solve(a, b, 0, 0, n); }
};

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  SegmentTree st(n, a);
  int ans = -1;
  rep(i, n) { ans = max(ans, gcd(st.solve(0, i), st.solve(i + 1, n))); }
  cout << ans << endl;
  return 0;
}
