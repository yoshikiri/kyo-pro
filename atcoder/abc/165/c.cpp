#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int n, m, q;
std::vector<int> a, b, c, d;
int ans;

void dfs(std::vector<int> A) {
  if (A.size() == n + 1) {
    // for (auto v : A) std::cout << v << ' ';
    // std::cout << '\n';
    int now = 0;
    rep(i, q) {
      if (A[b[i]] - A[a[i]] == c[i]) now += d[i];
    }
    ans = std::max(ans, now);
    return;
  }

  A.push_back(A.back());
  while (A.back() <= m) {
    dfs(A);
    A.back()++;
  }
}

int main() {
  std::cin >> n >> m >> q;

  a = b = c = d = std::vector<int>(q);

  rep(i, q) { std::cin >> a[i] >> b[i] >> c[i] >> d[i]; }

  dfs(std::vector<int>(1, 1));

  std::cout << ans << '\n';
  return 0;
}
