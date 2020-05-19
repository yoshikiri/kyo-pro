#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int nq;
  cin >> nq;

  vector<int> vs(s.length());
  rep(i, s.length()) { vs[i] = s[i] - 'a'; }

  rep(i, nq) {
    int q;
    cin >> q;
    if (q == 1) {
      int i, c;
      cin >> i >> c;
      s[--i] = c;
    } else {
      int l, r;
      cin >> l >> r;
    }
  }
  return 0;
}
