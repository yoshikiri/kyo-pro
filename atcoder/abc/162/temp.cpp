#include <iostream>
#include <string>

int main() {
  int N;
  std::string S;

  std::cin >> N;
  std::cin >> S;

  long long r = 0, g = 0, b = 0;

  for (int i = 0; i < N; i++) {
    if (S[i] == 'R')
      r++;
    else if (S[i] == 'G')
      g++;
    else
      b++;
  }

  long long cnt = r * g * b;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (S[i] == S[j])
        continue;

      int k = 2 * j - i;
      if (k > N - 1)
        break;
      if (S[i] != S[j] && S[j] != S[k] && S[i] != S[k]) {
        cnt--;
      }
    }
  }

  std::cout << cnt << '\n';

  return 0;
}