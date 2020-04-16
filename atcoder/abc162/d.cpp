#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  std::string S;

  std::cin >> N;
  std::cin >> S;

  std::vector<int> R, G, B;

  for (int i = 0; i < N; i++) {
    if (S[i] == 'R')
      R.push_back(i);
    else if (S[i] == 'G')
      G.push_back(i);
    else
      B.push_back(i);
  }

  int cnt = 0;

  for (int i = 0; i < N - 2; i++) {
    char a = S[i];
    for (int j = i + 1; j < N - 1; j++) {
      char b = S[j];
      if (a == b) {
        continue;
      }

      if ('R' != a && 'R' != b) {
        for (int k = 0; k < R.size(); k++) {
          if (R[k] > j && j - i != R[k] - j) {
            // std::cout << i << j << R[k] << '\n';
            cnt++;
          }
        }
      } else if ('G' != a && 'G' != b) {
        for (int k = 0; k < G.size(); k++) {
          if (G[k] > j && j - i != G[k] - j) {
            // std::cout << i << j << G[k] << '\n';
            cnt++;
          }
        }
      } else {
        for (int k = 0; k < B.size(); k++) {
          if (B[k] > j && j - i != B[k] - j) {
            // std::cout << i << j << B[k] << '\n';
            cnt++;
          }
        }
      }
    }
  }

  std::cout << cnt << '\n';
  return 0;
}