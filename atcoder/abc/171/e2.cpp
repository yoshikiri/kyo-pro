#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int s = 0;
  rep(i, n) s ^= a[i];
  rep(i, n) {
    int b = s ^ a[i];
    cout << b << endl;
  }
  return 0;
}
