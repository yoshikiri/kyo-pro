#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = (c + b - 1) / b;
  int y = (a + d - 1) / d;
  if (x > y)
    puts("No");
  else
    puts("Yes");

  return 0;
}
