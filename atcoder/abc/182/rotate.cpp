#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h = 3, w = 6;
  vector<vector<int>> array(h, vector<int>(w));
  rep(i, h) rep(j, w) array[i][j] = i * w + j;

  int mi[] = {h, w, h, w, h};
  int mj[] = {w, h, w, h, w};
  rep(d, 4) {
    rep(i, mi[d]) {
      rep(j, mj[d]) printf("%2d ", array[i][j]);
      cout << endl;
    }
    int next[mi[d + 1]][mj[d + 1]];
    rep(i, mi[d]) rep(j, mj[d]) next[j][i] = array[mi[d] - i - 1][j];
    array = vector<vector<int>>(mi[d + 1], vector<int>(mj[d + 1]));
    rep(i, mi[d + 1]) rep(j, mj[d + 1]) array[i][j] = next[i][j];
  }

  return 0;
}