#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll choose(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  ll x = 1, y = 1;
  rep(i, b) {
    x *= (ll)a - i;
    y *= (ll)i + 1;
  }

  printf("x, y: %lld, %lld\n", x, y);
  return x / y;
}

int pow(int k, int n) {
  int ret = 1;
  rep(i, n) ret *= k;
  return ret;
}

int main() {
  string n;
  int k;
  cin >> n >> k;

  int d = n.length();

  int r = pow(9, k);

  ll ans = 0;
  for (int i = 1; i < d; ++i) {
    cout << i << endl;
    // if (i - k < 0) continue;
    ans += (ll)r * choose(i - 1, i - k);
  }

  // int a = n[0] - '0';
  // ans += (a - 1) * choose(d - 1, k - 1) * pow(9, k - 1);

  cout << ans << endl;

  int cnt = 0;
  for (int i = 0; i < d; ++i) {
    printf("%d, %d\n", i, cnt);
    if (i == 0) {
      ans += ((n[i] - '0') - 1) * choose(d - 1, d - k) * pow(9, k - 1);
      printf("%d, %lld\n", i,
             ((n[i] - '0') - 1) * choose(d - 1, d - k) * pow(9, k - 1));
    } else {
      printf("(1) %d, %lld\n", i,
             (n[i] - '0') * choose(d - i - 1, d - k - cnt) *
                 pow(9, k - i - 1 + cnt));
      printf("(2) %d, %lld\n", i,
             choose(d - i - 1, d - k - 1 - cnt) * pow(9, k - i + cnt));

      ans += (n[i] - '0') * choose(d - i - 1, d - k - cnt) *
             pow(9, k - i - 1 + cnt);
      ans += choose(d - i - 1, d - k - 1 - cnt) * pow(9, k - i + cnt);
    }
    if (n[i] == '0') ++cnt;
  }

  cout << ans << endl;

  // {
  //   int cnt = 0;
  //   for (char c : n)
  //     if (c != '0') ++cnt;
  //   if (cnt == k) ++ans;
  // }

  cout << ans << endl;

  return 0;
}
