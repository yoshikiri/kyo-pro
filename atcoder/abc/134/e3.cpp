#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; --i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  multiset<int> s;
  rep(i, n) {
    auto it = s.lower_bound(a[i]);
    if (it != s.begin()) s.erase(--it);
    s.insert(a[i]);
  }
  cout << s.size() << endl;
  return 0;
}
