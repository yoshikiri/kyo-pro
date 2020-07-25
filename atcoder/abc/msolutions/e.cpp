#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void comb(vector<int> a, int k, int *u) {
  if (a.size() == k) return a;
}

void perm(vector<int> a, int n, int *used) {
  if (a.size() == n) {
    for (auto x : a) cout << x << " ";
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<pair<P, int>> v(n);
  rep(i, n) {
    int x, y, p;
    cin >> x >> y >> p;
    v[i] = make_pair(make_pair(x, y), p);
  }

  for (int x = -10000; x <= 10000; ++x) {
    for (int y = -10000; y <= 10000; ++y) {
    }
  }
  return 0;
}
