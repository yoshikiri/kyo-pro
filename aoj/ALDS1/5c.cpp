#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Point {
  double x;
  double y;
};

void koch(Point p1, Point p2, int n, int cnt) {
  if (cnt >= n) {
    std::cout << p1.x << ' ' << p1.y << '\n';
    return;
  }

  cnt++;

  Point s{p1.x + (p2.x - p1.x) / 3.0, p1.y + (p2.y - p1.y) / 3.0};
  Point t{p2.x - (p2.x - p1.x) / 3.0, p2.y - (p2.y - p1.y) / 3.0};
  Point v{t.x - s.x, t.y - s.y};
  Point u{s.x + (v.x - sqrt(3) * v.y) / 2.0, s.y + (sqrt(3) * v.x + v.y) / 2.0};

  koch(p1, s, n, cnt);
  koch(s, u, n, cnt);
  koch(u, t, n, cnt);
  koch(t, p2, n, cnt);
}

// s, t, u
void koch2(Point p1, Point p2, int n) {
  if (n < 1) {
    return;
  }

  Point s{p1.x + (p2.x - p1.x) / 3.0, p1.y + (p2.y - p1.y) / 3.0};
  Point t{p2.x - (p2.x - p1.x) / 3.0, p2.y - (p2.y - p1.y) / 3.0};
  Point v{t.x - s.x, t.y - s.y};
  Point u{s.x + (v.x - sqrt(3) * v.y) / 2.0, s.y + (sqrt(3) * v.x + v.y) / 2.0};

  koch2(p1, s, n - 1);
  std::cout << s.x << ' ' << s.y << '\n';

  koch2(s, u, n - 1);
  std::cout << u.x << ' ' << u.y << '\n';

  koch2(u, t, n - 1);
  std::cout << t.x << ' ' << t.y << '\n';

  koch2(t, p2, n - 1);
}

int main() {
  int n;
  std::cin >> n;

  Point p1{0.0, 0.0}, p2{100.0, 0.0};

  std::cout << p1.x << ' ' << p1.y << '\n';
  koch2(p1, p2, n);
  std::cout << p2.x << ' ' << p2.y << '\n';
  return 0;
}
