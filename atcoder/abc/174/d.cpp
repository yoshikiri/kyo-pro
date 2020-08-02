#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> w, r;
  rep(i, n) {
    if (s[i] == 'R') r.push_back(i);
    if (s[i] == 'W') w.push_back(i);
  }

  sort(w.begin(), w.end());
  sort(r.rbegin(), r.rend());

  if (w.size() == 0 || r.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  r.push_back(0);
  w.push_back(1001001001);

  int ans = 0;
  int wc = 0, rc = 0;
  int wMin = w[wc];
  int rMax = r[rc];
  while (wMin <= rMax) {
    ++wc, ++rc, ++ans;
    wMin = w[wc];
    rMax = r[rc];
  }

  cout << ans << endl;
  return 0;
}
