#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)

void printArray(int *A, int n) {
  rep(i, n) {
    std::cout << A[i];
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }
}

void combi(int k, int *S, int n) {
  if (k == 0) {
    printArray(S, n);
    return;
  }

  S[k - 1] = 0;
  combi(k - 1, S, n);
  S[k - 1] = 1;
  combi(k - 1, S, n);
}

void combi2(int k, int *S, int n) {
  if (k == n) {
    printArray(S, n);
    return;
  }

  S[k] = 0;
  combi2(k + 1, S, n);
  S[k] = 1;
  combi2(k + 1, S, n);
}

bool solve(int *A, int n, int k, int m) {
  if (m == 0) {
    return true;
  }
  if (k == n) {
    return false;
  }

  return solve(A, n, k + 1, m - A[k]) || solve(A, n, k + 1, m);
}

bool solve2(int *A, int n, int k, int m) {
  if (m == 0) {
    return true;
  }
  if (k == n) {
    return false;
  }
  return solve2(A, n, k + 1, m) || solve2(A, n, k + 1, m - A[k]);
}

bool solve3(int *A, int n, int k, int m) {
  if (m == 0) {
    return true;
  }
  if (k < 0 || m < 0) {
    return false;
  }
  return solve3(A, n, k - 1, m) || solve3(A, n, k - 1, m - A[k]);
}

int main() {
  int n, q;
  std::cin >> n;
  int a[n];
  rep(i, n) std::cin >> a[i];
  std::cin >> q;
  int m[q];
  rep(i, q) std::cin >> m[i];

  int *S = new int[n];
  rep(i, n) S[n] = 0;

  rep(i, q) {
    int ans = solve3(a, n, n - 1, m[i]);
    if (ans) {
      std::cout << "yes" << '\n';
    } else {
      std::cout << "no" << '\n';
    }
  }
  return 0;
}
