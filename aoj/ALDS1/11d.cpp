#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int SIZE = 100001;
int group[SIZE];

void assignGroup(int u, int g, std::vector<int> *a) {
  if (group[u] != 0) return;

  group[u] = g;
  for (auto v : a[u]) {
    if (group[v] == 0) assignGroup(v, g, a);
  }
}

bool isConnected(int s, int t) { return group[s] == group[t]; }

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a[n];

  rep(i, m) {
    int s, t;
    std::cin >> s >> t;
    a[s].push_back(t);
    a[t].push_back(s);
  }

  int g = 0;
  rep(i, n) {
    if (group[i] == 0) { assignGroup(i, ++g, a); }
  }

  int q;
  std::cin >> q;
  rep(i, q) {
    int s, t;
    std::cin >> s >> t;
    if (isConnected(s, t))
      std::cout << "yes" << '\n';
    else
      std::cout << "no" << '\n';
  }

  return 0;
}
