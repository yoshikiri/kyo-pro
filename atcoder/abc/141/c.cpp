#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> v(n, k - q);
  rep(i, q) {
    int a;
    cin >> a;
    --a;
    ++v[a];
  }
  for (auto x : v) {
    if (x > 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
