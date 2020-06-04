#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n - 1) {
    int a;
    cin >> a;
    --a;
    ++d[a];
  }

  rep(i, n) { cout << d[i] << endl; }
  return 0;
}
