#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct SegmentTree {
  vector<int> d;
  int n;
  SegmentTree(int m) {
    n = 1;
    while (n < m) n *= 2;
    d = vector<int>(2 * n - 1);
  }

  void update(int i, int x) {
    i += n - 1;
    d[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      d[i] = d[i * 2 + 1] ^ d[i * 2 + 2];
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  int query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return 0;
    } else if (a <= l && r <= b) {
      return d[k];
    } else {
      int vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return vl ^ vr;
    }
  }

  int value(int i) { return d[n - 1 + i]; }
};

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree st(n);
  rep(i, n) {
    int a;
    cin >> a;
    st.update(i, a);
  }

  rep(iq, q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      st.update(x - 1, st.value(x - 1) ^ y);
    } else {
      printf("%d\n", st.query(x - 1, y));
    }
  }
  return 0;
}
