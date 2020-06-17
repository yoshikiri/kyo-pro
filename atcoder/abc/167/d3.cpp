#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  ll k;
  cin >> n >> k;
  int a[n];
  rep(i, n) {
    cin >> a[i];
    --a[i];
  }

  int loop = 0, line = 0;
  vector<int> v(n, -1), u(n, -1);
  int cur = 0;
  rep(i, n) {
    v[cur] = i;
    u[i] = cur;
    int next = a[cur];
    if (v[next] == -1)
      cur = next;
    else {
      loop = i + 1 - v[next];
      line = v[next];
      break;
    }
  }

  ll ans = 0;
  if (k <= line)
    ans = u[k];
  else {
    k -= line;
    k %= loop;
    ans = u[line + k];
  }
  cout << ans + 1 << endl;
  return 0;
}
