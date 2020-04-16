#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isPrime(int m) {
  double lim = std::sqrt(m);

  for (int i = 2; i <= lim; i++) {
    if (m % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  rep(i, n) { std::cin >> a[i]; }

  int cnt = 0;
  rep(i, n) {
    if (isPrime(a[i])) {
      cnt++;
    }
  }

  std::cout << cnt << '\n';

  return 0;
}