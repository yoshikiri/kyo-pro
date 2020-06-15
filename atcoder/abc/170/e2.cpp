#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAX = 200005;

int main() {
  int n, q;
  cin >> n >> q;
  int a[n], b[n];
  vector<multiset<int>> s(MAX);
  multiset<int> maxes;

  auto getMax = [&](int i) {
    if (s[i].size() == 0) return -1;
    return *s[i].rbegin();
  };

  auto delMax = [&](int i) {
    int x = getMax(b[i]);
    if (x != -1) maxes.erase(maxes.find(x));
  };

  auto addMax = [&](int i) {
    int x = getMax(b[i]);
    if (x != -1) maxes.insert(x);
  };

  auto del = [&](int i) {
    delMax(i);
    s[b[i]].erase(s[b[i]].find(a[i]));
    addMax(i);
  };

  auto add = [&](int i) {
    delMax(i);
    s[b[i]].insert(a[i]);
    addMax(i);
  };

  rep(i, n) {
    cin >> a[i] >> b[i];
    --b[i];
    add(i);
  }

  rep(i, q) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    del(c);
    b[c] = d;
    add(c);
    cout << *maxes.begin() << endl;
  }

  return 0;
}
