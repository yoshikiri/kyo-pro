#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

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

  vector<int> d;
  set<int> v;
  d.push_back(0);
  v.insert(0);
  int loop = 0;
  for (int i = 0; i < n - 1; ++i) {
    int nx = a[d[i]];
    if (v.find(nx) != v.end()) {
      loop = d.size() - distance(d.begin(), find(d.begin(), d.end(), nx));
      break;
    }
    d.push_back(nx);
    v.insert(nx);
  }

  int noLoop = d.size() - loop;
  if (k <= noLoop) {
    int ans = d[k];
    cout << ++ans << '\n';
    return 0;
  }
  int ans = d[noLoop + (k - noLoop) % loop];
  cout << ++ans << '\n';

  return 0;
}
