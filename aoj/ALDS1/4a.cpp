// 00:15 - 00:18

#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, q;
  std::cin >> n;
  int S[n];
  rep(i, n) std::cin >> S[i];
  std::cin >> q;
  int T[q];
  rep(i, q) std::cin >> T[i];

  int cnt = 0;
  rep(i, q) {
    rep(j, n) {
      if (T[i] == S[j]) {
        cnt++;
        break;
      }
    }
  }

  std::cout << cnt << '\n';
  return 0;
}