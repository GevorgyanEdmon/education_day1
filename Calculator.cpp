#include <iostream>

int main() {
  double a, b;
  char op;
  std::cin >> a >> op >> b;
  std::cout << (op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : (b ? a / b : 0)) << '\n';
  return 0;
}