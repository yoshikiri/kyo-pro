#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
  int n = 3, k = 11;
  int a[] = {7, 2, 9};

  rep(s, 1 << n) {
    int sum = 0;

    rep(i, n) {
      if (s >> i & 1) sum += a[i];
    }
    if (sum == k) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}