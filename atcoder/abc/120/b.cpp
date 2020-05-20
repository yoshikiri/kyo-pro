#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  int cnt = 0;
  vector<int> cd;
  for (int i = 1; i <= min(a, b); ++i) {
    if (a % i == 0 && b % i == 0) {
      cd.push_back(i);
      ++cnt;
    }
  }

  cout << cd[cd.size() - k] << '\n';
  return 0;
}
