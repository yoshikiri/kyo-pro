#include <iostream>
#include <string>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool isMonth(int x) { return 1 <= x && x <= 12; }

bool isYear(int x) { return 0 <= x && x <= 99; }

int main() {
  string s;
  cin >> s;

  int yy = 10 * (s[0] - '0') + (s[1] - '0');
  int mm = 10 * (s[2] - '0') + (s[3] - '0');

  if (isMonth(yy)) {
    if (isMonth(mm)) {
      cout << "AMBIGUOUS" << '\n';
      return 0;
    } else if (isYear(mm)) {
      cout << "MMYY" << '\n';
    }
  } else {
    if (isMonth(mm)) {
      cout << "YYMM" << '\n';
      return 0;
    } else {
      cout << "NA" << '\n';
    }
  }
  return 0;
}
