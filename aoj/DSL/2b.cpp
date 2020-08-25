#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct SegmentTree {
  int n;
  vector<int> v;
  SegmentTree(int n, int *a) : n(n), v(2 * n - 1) {
    rep(i, n) v[i + n - 1] = a[i];
    rep(i, n) {
      int j = i;
      while (j > 0) {
        j = (i - 1) / 2;
        v[j] = v[2 * j + 1] + v[2 * j + 2];
      }
    }
  }

  SegmentTree(int size) {
    n = 1;
    while (n < size)
      n *= 2;
    v = vector<int>(2 * n - 1, 0);
  }

  void add(int i, int x) {
    i += n - 1;
    v[i] += x;
    while (i > 0) {
      i = (i - 1) / 2;
      v[i] = v[2 * i + 1] + v[2 * i + 2];
    }
  }

  int solve(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l)
      return 0;
    if (a <= l && r <= b)
      return v[k];
    int c1 = solve(a, b, 2 * k + 1, l, (l + r) / 2);
    int c2 = solve(a, b, 2 * k + 2, (l + r) / 2, r);
    return c1 + c2;
  }

  int solve(int a, int b) { return solve(a, b, 0, 0, n); }
};

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree st(n);
  vector<ll> ans;
  rep(iq, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      --x;
      st.add(x, y);
    } else {
      --x, --y;
      ans.push_back(st.solve(x, y + 1));
    }
  }

  for (auto v : ans)
    cout << v << endl;
  return 0;
}
