#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int f(int x) {
  if (x == 0) return 0;
  int res = 1;
  rep(i, x) { res *= x - i; }

  return res;
}

int main() {
  int n;
  cin >> n;

  int a = 0, b = 0;
  int use[n];
  rep(i, n) use[i] = 0;
  rep(i, n) {
    int p;
    cin >> p;
    use[p] = 1;
    int u = 0;
    for (int j = 1; j < p; ++j) {
      u += use[j];
    }
    a += f(n - i - 1) * (p - 1 - u);
  }

  rep(i, n) use[i] = 0;
  rep(i, n) {
    int p;
    cin >> p;
    use[p] = 1;
    int u = 0;
    for (int j = 1; j < p; ++j) {
      u += use[j];
    }
    b += f(n - i - 1) * (p - 1 - u);
  }

  cout << abs(a - b) << endl;
  return 0;
}
