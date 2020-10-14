#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  sort(d.begin(), d.end());

  int l = d[n / 2 - 1];
  int r = d[n / 2];
  cout << r - l << endl;
  return 0;
}
