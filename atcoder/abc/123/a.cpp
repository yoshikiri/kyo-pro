#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n = 5;
  int a[n];
  rep(i, n) cin >> a[i];
  int k;
  cin >> k;

  bool ok = true;
  rep(i, n) rep(j, i) if (abs(a[i] - a[j]) > k) ok = false;

  cout << (ok ? "Yay!" : ":(") << endl;
  return 0;
}
