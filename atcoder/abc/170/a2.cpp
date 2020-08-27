#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n = 5;
  int sum = 0;
  rep(i, n) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << 15 - sum << endl;
  return 0;
}
