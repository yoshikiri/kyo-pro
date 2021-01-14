#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> q;
  rep(i, n) {
    int a;
    cin >> a;
    q.push(a);
  }
  rep(i, m) {
    int x = q.top();
    q.pop();
    q.push(x / 2);
  }
  ll ans = 0;
  while (!q.empty()) {
    int x = q.top();
    q.pop();
    ans += x;
  }
  cout << ans << endl;
  return 0;
}
