#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<string, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Rest {
  int id;
  string s;
  int p;

  Rest(int _id, string _s, int _p) : id(_id), s(_s), p(_p) {}

  bool operator<(const Rest &right) const {
    return s == right.s ? p > right.p : s < right.s;
  }
};

int main() {
  int n;
  cin >> n;
  vector<Rest> r;
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    r.push_back(Rest(i + 1, s, p));
  }

  sort(r.begin(), r.end());

  for (auto re : r) cout << re.id << endl;

  return 0;
}
