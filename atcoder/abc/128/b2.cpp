#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<pair<string, pair<int, int>>> v(n);
  rep(i, n) {
    cin >> v[i].first >> v[i].second.first;
    v[i].second.first *= -1;
    v[i].second.second = i + 1;
  }
  sort(v.begin(), v.end());
  rep(i, n) cout << v[i].second.second << endl;
  return 0;
}
