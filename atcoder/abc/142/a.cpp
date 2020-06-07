#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  if (n % 2 == 0)
    printf("%.10f\n", 0.5);
  else
    printf("%.10f\n", (double)(n / 2 + 1) / n);
  return 0;
}
