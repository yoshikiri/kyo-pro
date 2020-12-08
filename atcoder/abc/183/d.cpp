#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<P, int>> v(n);
  rep(i, n) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
  sort(v.begin(), v.end());

  priority_queue<P> q;
  ll sum = 0;
  rep(i, n) {
    while (!q.empty() && (-q.top().first <= v[i].first.first)) {
      auto x = q.top();
      q.pop();
      sum -= x.second;
    }
    sum += v[i].second;
    q.push({-v[i].first.second, v[i].second});
    if (sum > w) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
