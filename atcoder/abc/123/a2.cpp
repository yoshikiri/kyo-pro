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
  cout << (abs(a[0] - a[4]) <= k ? "Yay!" : ":(") << endl;
  return 0;
}
