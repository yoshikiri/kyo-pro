#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void assignGroup(int u, int *group, int g, vector<vector<int>> &t) {
  if (group[u] != -1) return;
  group[u] = g;
  for (auto v : t[u]) { assignGroup(v, group, g, t); }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> t(n);
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    --x;
    --y;
    t[x].push_back(y);
    t[y].push_back(x);
  }

  int g = 0;
  int group[n];
  rep(i, n) group[i] = -1;
  rep(i, n) {
    if (group[i] == -1) {
      assignGroup(i, group, g, t);
      ++g;
    }
  }

  set<int> s;
  rep(i, n) { s.insert(group[i]); }

  cout << s.size() << '\n';

  return 0;
}
