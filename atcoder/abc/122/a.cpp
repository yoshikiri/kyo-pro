#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  char b;
  cin >> b;

  char ans;
  if (b == 'A') ans = 'T';
  if (b == 'T') ans = 'A';
  if (b == 'G') ans = 'C';
  if (b == 'C') ans = 'G';

  cout << ans << '\n';
  return 0;
}
