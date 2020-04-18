#include <algorithm>
#include <iostream>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool canAllocate(int *w, int n, int k, int p) {
  int i = 0;
  int x = 0;

  while (x < k) {
    int sum = 0;
    while (i < n && sum + w[i] <= p) {
      sum += w[i];
      i++;
    }
    // std::cout << "x: " << x << "i: " << i << "p: " << p << '\n';
    x++;
    if (i == n)
      return true;
  }
  return false;
}

int check(int *w, int n, int k, int p) {
  int i = 0;
  int x = 0;

  while (x < k) {
    int sum = 0;
    while (i < n && sum + w[i] <= p) {
      sum += w[i];
      i++;
      if (i == n)
        return n;
    }
    x++;
  }
  return i;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int w[n];
  rep(i, n) std::cin >> w[i];

  int left = *std::max_element(w, w + n) - 1;
  int right = std::accumulate(w, w + n, 0);
  int m = (left + right) / 2;

  while (right - left > 1) {
    m = (left + right) / 2;
    if (check(w, n, k, m) >= n)
      right = m;
    else
      left = m;
  }

  std::cout << right << '\n';
  return 0;
}
