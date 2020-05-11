#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  ll k;
  cin >> n >> k;

  int a[n + 1];
  for (int i = 1; i < n + 1; ++i) cin >> a[i];

  vector<int> r;
  vector<int> ord(n + 1, -1);

  int now = 1;
  while (ord[now] == -1) {
    ord[now] = r.size();
    r.push_back(now);
    now = a[now];
  }

  int loop = r.size() - ord[now];
  int line = ord[now];

  if (k < line) {
    cout << r[k] << '\n';
  } else {
    cout << r[line + (k - line) % loop] << '\n';
  }

  return 0;
}
