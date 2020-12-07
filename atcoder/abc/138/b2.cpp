#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  double sum = 0;
  rep(i, n) sum += 1.0 / a[i];
  printf("%.15f\n", 1 / sum);
  return 0;
}
