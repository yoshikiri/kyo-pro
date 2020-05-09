#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using P = std::pair<int, int>;

int main() {
  int n, k;
  std::cin >> n >> k;

  int mx = (n - 1) * (n - 2) / 2;
  if (k > mx) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::vector<P> ans;
  rep(i, n - 1) { ans.push_back(P(i + 1, n)); }

  int add = mx - k;
  std::vector<P> edge;
  rep(i, n - 1) rep(j, i) edge.push_back(P(i + 1, j + 1));
  rep(i, add) ans.push_back(edge[i]);

  std::cout << ans.size() << '\n';
  rep(i, ans.size()) {
    std::cout << ans[i].first << " " << ans[i].second << '\n';
  }

  return 0;
}
