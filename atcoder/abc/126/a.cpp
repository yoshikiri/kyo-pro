#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  s[k - 1] = std::tolower(s[k - 1]);
  cout << s << endl;
  return 0;
}
