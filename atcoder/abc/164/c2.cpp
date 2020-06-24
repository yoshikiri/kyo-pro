#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  set<string> g;
  rep(i, n) {
    string s;
    cin >> s;
    g.insert(s);
  }
  int ans = g.size();
  cout << ans << endl;
  return 0;
}
