#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T> struct SegmentTree {
  using F = function<T(T, T)>;
  T n;
  vector<T> d;
  const F f;
  const T e;

  // 要素数, 操作関数, 単位元
  SegmentTree(T m, F f, T e) : f(f), e(e) {
    n = 1;
    while (n < m) n *= 2;
    d = vector<T>(2 * n, e);
  }

  void update(int i, T x) {
    i += n;
    d[i] = x;
    while (i > 1) {
      i /= 2;
      d[i] = f(d[2 * i], d[2 * i + 1]);
    }
  }

  // [a, b)
  T query(int a, int b) { return query_sub(a, b, 1, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    // index k: [l, r)
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return d[k];
    T lv = query_sub(a, b, 2 * k, l, (l + r) / 2);
    T rv = query_sub(a, b, 2 * k + 1, (l + r) / 2, r);
    return f(lv, rv);
  }

  T get(int i) { return d[n + i]; }
};
