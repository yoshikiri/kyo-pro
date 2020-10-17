#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int x[n];
  rep(i, n) cin >> x[i];
  ll s1 = 0;
  double s2 = 0;
  int s3 = 0;
  rep(i, n) {
    s1 += abs(x[i]);
    s2 += (ll)abs(x[i]) * abs(x[i]);
    s3 = max(s3, abs(x[i]));
  }
  s2 = sqrt(s2);
  printf("%lld\n%.15f\n%d\n", s1, s2, s3);
  return 0;
}
