#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int d[n];
  rep(i, n) d[i] = i + 1;

  int dif = 0;
  rep(i, n) {
    int p;
    cin >> p;
    if (p != d[i]) ++dif;
  }

  if (dif <= 2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
