// failed compiles: 0
// failed runs: 0
// time taken: 5 minutes

#include <iostream>

using BIG = unsigned long long int;

BIG factorial(BIG n) {
  if (n == 0 || n == 1)
    return 1;

  return n * factorial(n - 1);
}

int main() {
  BIG n;

  std::cout << "Type in a whole number to evaluate its factorial: ";
  std::cin >> n;

  std::cout << n << "! = " << factorial(n) << std::endl;
  return 0;
}
