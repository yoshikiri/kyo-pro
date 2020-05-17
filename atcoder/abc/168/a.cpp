#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  string ans;

  n %= 10;

  if (n == 2 || n == 4 || n == 5 || n == 7 || n == 9)
    ans = "hon";
  else if (n == 0 || n == 1 || n == 6 || n == 8)
    ans = "pon";
  else if (n == 3)
    ans = "bon";

  cout << ans << '\n';
  return 0;
}
