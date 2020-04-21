#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool solve(int *A, int k, int x) {
  if (x == 0)
    return true;
  if (k == 0)
    return false;
  return solve(A, k - 1, x) || solve(A, k - 1, x - A[k - 1]);
}

int main() {
  int n, q;
  std::cin >> n;
  int A[n];
  rep(i, n) std::cin >> A[i];
  std::cin >> q;
  int m[q];
  rep(i, q) std::cin >> m[i];

  rep(i, q) {
    if (solve(A, n, m[i]))
      std::cout << "yes" << '\n';
    else
      std::cout << "no" << '\n';
  }

  return 0;
}
