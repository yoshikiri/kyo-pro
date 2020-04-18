#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int binarySearch(int *A, int n, int key) {
  int left = -1;
  int right = n;
  while (right - left > 1) {
    int m = (left + right) / 2;

    if (A[m] == key)
      return 1;

    if (key < A[m]) {
      right = m;
    } else {
      left = m;
    }
  }

  return 0;
}

int main() {
  int n, q;
  std::cin >> n;
  int S[n];
  rep(i, n) std::cin >> S[i];
  std::cin >> q;
  int T[q];
  rep(i, q) std::cin >> T[i];

  int cnt = 0;
  rep(i, q) { cnt += binarySearch(S, n, T[i]); }

  std::cout << cnt << '\n';
  return 0;
}
