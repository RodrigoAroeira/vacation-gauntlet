// failed compiles: 1
// failed runs: 8
// time taken: 40 minutes

#include "Timer.h"
#include <ctime>
#include <functional>
#include <iostream>

using BIG = unsigned long long int;

BIG fibr(BIG n) {

  if (n <= 1)
    return n;

  return fibr(n - 1) + fibr(n - 2);
}

BIG fib(BIG n) {
  BIG temp, a = 0, b = 1;

  if (n <= 1)
    return n;

  for (int i = 2; i <= n; i++) {
    temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}

int main() {
  BIG n, r;
  int opt;
  bool flag = true;
  std::cout << "Type in the n-th fibonacci number to evaluate: ";
  std::cin >> n;
  std::function<BIG(BIG)> method;

  while (flag) {
    std::cout << "Select method: \n1. Recursion\n2. Iteration" << std::endl;
    std::cin >> opt;
    switch (opt) {
    case 1:
      method = fibr;
      flag = false;
      break;
    case 2:
      method = fib;
      flag = false;
      break;
    default:
      std::cout << "Invalid method." << std::endl;
    }
  }

  {
    utils::Timer _;
    r = method(n);
  }

  std::cout << n << "-th fibonacci is: " << r << std::endl;
  std::cout << "Chosen method: ";

  std::cout << (opt == 1 ? "recursion" : "iteration") << std::endl;
}
