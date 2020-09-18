#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int v[n];
  rep(i, n) cin >> v[i];
  vector<int> l(n + 1), r(n + 1);
  rep(i, n) {
    l[i + 1] = l[i] + v[i];
    r[i + 1] = r[i] + v[n - i - 1];
  }

  int ans = 0;
  for (int a = 0; a <= min(n, k); ++a) {
    for (int b = 0; b <= min(n, k); ++b) {
      if (a + b > min(n, k)) break;
      int sum = 0;
      vector<int> neg;
      rep(i, a) {
        if (v[i] >= 0)
          sum += v[i];
        else
          neg.push_back(v[i]);
      }
      rep(i, b) {
        if (v[n - i - 1] >= 0)
          sum += v[n - i - 1];
        else
          neg.push_back(v[n - i - 1]);
      }
      sort(neg.begin(), neg.end());
      rep(i, neg.size()) {
        if (i + (k - (a + b)) >= (int)neg.size()) break;
        sum += neg[i + (k - (a + b))];
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
