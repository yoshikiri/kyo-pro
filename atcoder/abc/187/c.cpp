#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  set<string> s;
  rep(i, n) {
    string x;
    cin >> x;
    s.insert(x);
  }

  for (auto x : s) {
    if (s.find("!" + x) != s.end()) {
      cout << x << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
  return 0;
}
