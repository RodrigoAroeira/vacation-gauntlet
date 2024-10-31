#include <cstddef>
#include <cstring>
#include <iostream>

static const char ASCII_CASE_DIFF = 'a' - 'A';

bool isLower(char c) { return c >= 'a' && c <= 'z'; }

bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }

void reverse(char *str) {
  size_t len = std::strlen(str);
  for (size_t i = 0; i < len / 2; i++)
    std::swap(str[i], str[len - i - 1]);
}

void uppercase(char *str) {
  for (size_t i = 0; str[i]; i++) {
    if (isLower(str[i]))
      str[i] -= ASCII_CASE_DIFF;
  }
}

void lowercase(char *str) {
  for (size_t i = 0; str[i]; i++)
    if (isUpper(str[i]))
      str[i] += ASCII_CASE_DIFF;
}

void switchcase(char *str) {
  for (size_t i = 0; str[i]; i++) {
    char &c = str[i];
    char temp[2] = {c, '\0'};
    if (isUpper(c)) {
      lowercase(temp);
    } else if (isLower(c)) {
      uppercase(temp);
    }
    c = temp[0];
  }
}

int main(int argc, char *argv[]) {
  std::cout << "> ";
  std::string tmp;
  std::getline(std::cin, tmp);

  char str[tmp.size() + 1];
  std::strcpy(str, tmp.c_str());

  switchcase(str);
  std::cout << str << std::endl;
  reverse(str);
  std::cout << str << std::endl;
  uppercase(str);
  std::cout << str << std::endl;
  lowercase(str);
  std::cout << str << std::endl;
  reverse(str);
  std::cout << str << std::endl;
  return 0;
}
