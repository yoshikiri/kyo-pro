#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int modpow(int x, int n, int p) {
  if (n == 0) return 1;
  if (n % 2 == 0)
    return modpow(x * x % p, n / 2, p);
  else
    return modpow(x * x % p, n / 2, p) * x % p;
}

int main() {
  std::string s;
  std::cin >> s;

  int n = s.length();
  int a[n + 1], b[2019] = {0};

  a[n] = 0;
  b[0]++;
  for (int i = n - 1; i >= 0; --i) {
    a[i] =
        (a[i + 1] + modpow(10, n - i - 1, 2019) * (s[i] - '0') % 2019) % 2019;
    b[a[i]]++;
  }

  int sum = 0;
  rep(i, 2019) {
    int m = b[i];
    sum += m * (m - 1) / 2;
  }

  std::cout << sum << '\n';

  return 0;
}
