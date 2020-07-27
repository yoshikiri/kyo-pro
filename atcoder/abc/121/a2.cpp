#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << H * W - h * W - w * H + h * w << endl;
  return 0;
}
