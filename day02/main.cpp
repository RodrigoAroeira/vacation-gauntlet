// failed compiles: 0
// failed runs: 2
// time taken: 25 minutes

#include <iostream>


int main(int argc, char const *argv[]){
    double temp;
    char scale;

    if(argc>1){ // argv[1] = temperatura; argv[2] = escala (K, C, F, R)
        temp = std::stod(argv[1]);
        scale = *argv[2];
    }else {
        std::cout << "Temperature (with scale [K, C, F, R]): ";
        std::cin >> temp >> scale;
    }

    switch(scale){
        case 'F':
            temp = ((temp-32)/1.8)+273.15;
            break;
        case 'C':
            temp = (temp+273.15);
            break;
        case 'R':
            temp = temp/(1.8);
            break;
        default:
            break;
    }
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "Kelvin: " << temp << "K" << std::endl;
    std::cout << "Celsius: " << temp-273.15 << "°C" << std::endl;
    std::cout << "Fahrenheit: " << (temp-273.15)*(1.8) + 32 << "°F" << std::endl;
    std::cout << "Rankine: " << temp*1.8 << "°R" << std::endl;
}