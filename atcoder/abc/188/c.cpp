#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int size = 1 << n;
  vector<P> v(size);
  rep(i, size) {
    int x;
    cin >> x;
    v[i] = make_pair(x, i + 1);
  }
  rep(i, n - 1) {
    vector<P> t(size / 2);
    for (int j = 0; j < size - 1; j += 2) t[j / 2] = max(v[j], v[j + 1]);
    v = t;
  }
  cout << min(v[0], v[1]).second << endl;
  return 0;
}
