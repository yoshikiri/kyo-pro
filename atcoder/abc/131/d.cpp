// 17:05 - 17:14
#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using P = std::pair<int, int>;

// struct Job {
//   int a, b;
// };
//
// bool comp(const Job &j1, const Job &j2) { return j1.b < j2.b; }

int main() {
  int n;
  std::cin >> n;
  // Job jobs[n];
  std::vector<P> tasks(n);

  // rep(i, n) { std::cin >> jobs[i].a >> jobs[i].b; }
  rep(i, n) { std::cin >> tasks[i].second >> tasks[i].first; }

  // std::sort(jobs, jobs + n, comp);
  std::sort(tasks.begin(), tasks.end());

  int sum = 0;
  rep(i, n) {
    sum += tasks[i].second;
    if (sum > tasks[i].first) {
      std::cout << "No" << '\n';
      return 0;
    }
  }

  std::cout << "Yes" << '\n';
  return 0;
}
