// failed compiles: 0
// failed runs: 0
// time taken: 5 minutes

#include <iostream>
#include <sstream>
#include <string>

using BIG = long double;

BIG factorial(BIG n) {
  if (n == 0 || n == 1)
    return 1;

  return n * factorial(n - 1);
}

std::string formatWithCommas(BIG value) {
  std::stringstream ss;

  ss.imbue(std::locale(""));
  ss << std::fixed << value;
  std::string result = ss.str();
  size_t decimal_pos = result.find('.');

  if (decimal_pos != std::string::npos)
    result = result.substr(0, decimal_pos);

  return result;
}

int main(int argc, char **argv) {
  unsigned n;

  if (argc < 2) {
    std::cout << "Type in a whole number to evaluate its factorial: ";
    std::cin >> n;
  } else {
    n = std::stold(argv[1]);
  }

  std::cout << n << "! = " << formatWithCommas(factorial(n)) << std::endl;
  return 0;
}
