#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int s, w;
  cin >> s >> w;
  if (s <= w)
    puts("unsafe");
  else
    puts("safe");
  return 0;
}
