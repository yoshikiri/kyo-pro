#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int p[n];
  rep(i, n) cin >> p[i];
  int cnt = 0;
  rep(i, n) {
    if (p[i] != (i + 1)) ++cnt;
  }
  cout << ((cnt == 0 || cnt == 2) ? "YES" : "NO") << endl;
  return 0;
}
