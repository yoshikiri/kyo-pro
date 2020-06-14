#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAX = 200005;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);

  vector<multiset<int>> s(MAX);
  multiset<int> maxes;

  auto getMax = [&](int i) {
    if (s[i].size() == 0) return -1;
    return *(s[i].rbegin());
  };

  auto addK = [&](int i) {
    int x = getMax(i);
    if (x == -1) return;
    maxes.insert(x);
  };

  auto delK = [&](int i) {
    int x = getMax(i);
    if (x == -1) return;
    maxes.erase(maxes.find(x));
  };

  auto addE = [&](int i, int x) {
    delK(i);
    s[i].insert(x);
    addK(i);
  };

  auto delE = [&](int i, int x) {
    delK(i);
    s[i].erase(s[i].find(x));
    addK(i);
  };

  rep(i, n) {
    cin >> a[i] >> b[i];
    addE(b[i], a[i]);
  }

  rep(i, q) {
    int c, d;
    cin >> c >> d;
    --c;
    delE(b[c], a[c]);
    b[c] = d;
    addE(b[c], a[c]);
    int ans = *maxes.begin();
    printf("%d\n", ans);
  }

  return 0;
}
