#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string S;
  cin >> S;

  auto ok = [](char c) { return c == 'A' || c == 'T' || c == 'G' || c == 'C'; };
  int ans = 0;

  rep(i, S.length()) {
    int cnt = 0;
    for (int j = i; j < S.length(); ++j) {
      if (ok(S[j])) {
        ++cnt;
      } else {
        break;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}
