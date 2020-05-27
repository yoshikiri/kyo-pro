#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> res(n, 0), wa(n, 0);
  int cnt = 0;
  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;
    --p;

    if (s == "AC") {
      if (res[p]) continue;
      res[p] = 1;
      cnt += wa[p];
    } else {
      if (res[p] == 1) continue;
      ++wa[p];
    }
  }

  int ac = 0;
  rep(i, n) ac += res[i];

  cout << ac << " " << cnt << endl;

  return 0;
}
