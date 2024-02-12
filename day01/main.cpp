// failed compiles: 0
// failed runs: 2
// time taken: 10 minutes

#include <iostream>

int main(int argc, char const *argv[]){
    std::string fala;

    if (argc < 2){
        std::cout << "Qual o seu nome?" << std::endl;
        std::cin >> fala;
    }
    else{
        fala = argv[1];
    }

    if(fala == "dolan"){
        std::cout << fala << ", voce e chucro e fede, " << fala << "!" << std::endl;
    }else{
        std::cout << "Hello World!" << std::endl;
        std::cout << "Hello, " << fala << "!" << std::endl;
    }
    return 0;
}