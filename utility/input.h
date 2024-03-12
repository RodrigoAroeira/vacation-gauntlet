//
// Created by Rodrigo on 26/02/2024.
//

#include <iostream>

#ifndef VACATION_GAUNTLET_INPUT_H

template <typename T>
T input(auto message){
    T n;
    std::cout << message;
    std::cin >> n;
    return n;
}

#define VACATION_GAUNTLET_INPUT_H

#endif //VACATION_GAUNTLET_INPUT_H
