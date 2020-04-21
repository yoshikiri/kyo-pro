#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool binarySearch(int *S, int left, int right, int x) {
  if (right - left <= 1)
    return false;

  int mid = (left + right) / 2;
  if (S[mid] == x)
    return true;

  if (S[mid] > x)
    return binarySearch(S, left, mid, x);
  else
    return binarySearch(S, mid, right, x);
}

bool binarySearch2(int *S, int n, int x) {
  int left = -1;
  int right = n;

  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (S[mid] == x)
      return true;

    if (x < S[mid])
      right = mid;
    else
      left = mid;
  }

  return false;
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
  // rep(i, q) { cnt += binarySearch(S, 0, n, T[i]); }
  rep(i, q) { cnt += binarySearch2(S, n, T[i]); }

  std::cout << cnt << '\n';

  return 0;
}
