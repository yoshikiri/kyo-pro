#include <iostream>
#include <queue>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, q, t = 0;
  std::cin >> n >> q;
  std::queue<std::string> names;
  std::queue<int> times;

  rep(i, n) {
    std::string name;
    int time;
    std::cin >> name >> time;
    names.push(name);
    times.push(time);
  }

  while (!times.empty()) {
    int time = times.front();
    if (time <= q) {
      t += time;
      std::cout << names.front() << ' ' << t << '\n';
      times.pop();
      names.pop();
    } else {
      t += q;
      times.push(time - q);
      times.pop();
      names.push(names.front());
      names.pop();
    }
  }
  return 0;
}