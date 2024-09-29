// failed compiles:
// failed runs:
// time taken:

#include <cmath>
#include <iostream>

bool isPrime(const int val) {
  if (val < 2)
    return false;

  for (int i = 3; i < std::sqrt(val); i++) {
    if (val % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int num;
  std::cout << "Digite um numero inteiro: ";
  std::cin >> num;

  std::cout << "isPrime(" + std::to_string(num) + ") = " << isPrime(num);
  std::cout << std::endl;
  return 0;
}
