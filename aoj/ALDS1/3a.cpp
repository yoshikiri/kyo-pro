#include <iostream>
#include <stack>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  std::string str;
  std::stack<int> s;

  while (std::cin >> str) {
    if (str[0] == '+') {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      s.push(a + b);
    } else if (str[0] == '-') {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      s.push(b - a);
    } else if (str[0] == '*') {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      s.push(a * b);
    } else {
      s.push(std::stoi(str));
    }
  }

  std::cout << s.top() << '\n';
  return 0;
}