#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  int order[n];
  rep(i, n) {
    int a;
    cin >> a;
    --a;
    order[a] = i + 1;
  }

  rep(i, n) printf("%d%c", order[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
