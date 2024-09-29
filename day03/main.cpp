// failed compiles: 2
// failed runs: 11
// time taken: 45 minutes

#include <iostream>

long double calc(long double a, char op, long double b) {
  long double A = a;
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case 'x':
  case '*':
    return a * b;
  case '/':
    if (b == 0) {
      std::cout << "Invalid operation: can't divide by zero.";
      return 0;
    }
    return a / b;
  case '^':
    for (int i = 0; i < b; ++i) {
      a *= A;
    }
    return a;
  default:
    std::cout << "Invalid Operator." << std::endl;
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  long double a = 0, b = 0, res = 0;
  char op;

  while (true) {
    std::cout << "Input the expression (Operators: +, -, *, /, ^) (first "
                 "operand as 0 to use last result)"
              << std::endl;
    std::cin >> a >> op >> b;
    a = a == 0 ? res : a;
    if (a == 0)
      a = res;
    res = calc(a, op, b);
    std::cout.precision(5);
    std::cout << a << op << b << " = " << res << std::endl;
  }
}
