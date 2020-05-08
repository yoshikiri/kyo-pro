// 17:05 - 17:14
#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Job {
  int a, b;
};

bool comp(const Job &j1, const Job &j2) { return j1.b < j2.b; }

int main() {
  int n;
  std::cin >> n;
  Job jobs[n];

  rep(i, n) { std::cin >> jobs[i].a >> jobs[i].b; }

  std::sort(jobs, jobs + n, comp);

  int sum = 0;
  rep(i, n) {
    sum += jobs[i].a;
    // std::cout << sum << '\n';
    if (sum > jobs[i].b) {
      std::cout << "No" << '\n';
      return 0;
    }
  }

  std::cout << "Yes" << '\n';
  return 0;
}
