#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  vector<int> d;
  for (int i = 1; i <= min(a, b); ++i) {
    if (a % i == 0 && b % i == 0) {
      d.push_back(i);
    }
  }

  sort(d.rbegin(), d.rend());
  cout << d[k - 1] << endl;
  return 0;
}
