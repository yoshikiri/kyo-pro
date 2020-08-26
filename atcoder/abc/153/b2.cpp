#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, n;
  cin >> h >> n;
  int sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
  }
  if (sum >= h)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
