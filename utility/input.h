//
// Created by Rodrigo on 26/02/2024.
//

#include <iostream>
#include <sstream>

#ifndef VACATION_GAUNTLET_INPUT_H

template <typename T>
T input(const std::string &message = "") {
  std::string line;
  T value;

  std::cout << message;

  std::stringstream ss(line);
  ss >> value;

  std::cin.clear();

  return value;
}

#define VACATION_GAUNTLET_INPUT_H

#endif // VACATION_GAUNTLET_INPUT_H
