// failed compiles: 1
// failed runs: 8
// time taken: 40 minutes

#include "Timer.h"
#include <chrono>
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
  std::string methodName;

  while (flag) {
    std::cout << "Select method: \n1. Recursion\n2. Iteration" << std::endl;
    std::cin >> opt;
    switch (opt) {
    case 1:
      method = fibr;
      flag = false;
      methodName = "Recursion";
      break;
    case 2:
      method = fib;
      flag = false;
      methodName = "Iteration";
      break;
    default:
      std::cout << "Invalid method." << std::endl;
    }
  }

  {
    auto runWithTimer = [&](auto durationType) {
      using toDur = decltype(durationType);
      utils::ScopedTimer<toDur> st(methodName);
      r = method(n);
    };

    if (methodName == "Recursion") {
      runWithTimer(std::chrono::milliseconds{});
    } else {
      runWithTimer(std::chrono::microseconds{});
    }
  }

  std::cout << n << "-th fibonacci is: " << r << std::endl;
}
