#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

int partition(int *a, int n, int left, int right) {
  int v = a[right - 1];
  int l = left;
  for (int i = left; i < right; ++i) {
    if (a[i] < v) { swap(&a[i], &a[l++]); }
  }
  swap(&a[l], &a[right - 1]);
  return l;
}

void quickSort(int *a, int n, int left, int right) {
  if (right - left <= 1) return;
  int q = partition(a, n, left, right);
  quickSort(a, n, left, q);
  quickSort(a, n, q, right);
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  rep(i, n) std::cin >> a[i];

  quickSort(a, n, 0, n);

  rep(i, n) {
    if (i) std::cout << ' ';
    std::cout << a[i];
  }
  std::cout << '\n';
  return 0;
}
