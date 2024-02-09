// failed compiles: 1
// failed runs: 8
// time taken: 40 minutes

#include <iostream>
#include <iomanip>
#include <ctime>

using BIG = long long int;

BIG fibr(BIG n){

    if(n <= 1)
        return n;

    return fibr(n-1) + fibr(n-2);
}

BIG fib(BIG n){
    BIG temp, a = 0, b = 1;

    if (n <= 1)
        return n;


    for (int i = 2; i <= n; i++){
        temp = a+b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    BIG n, r;
    int input;
    bool flag = true;
    std::cout << "Type in the n-th fibonacci number to evaluate: ";
    std::cin >> n;
    std::cout << "Select method: \n1. Recursion\n2. Iteration" << std::endl;
    std::cin >> input;
    clock_t t = clock();


    while(flag){
        switch (input){
            case 1:
                r = fibr(n-1);
                flag = false;
                break;
            case 2:
                r = fib(n);
                flag = false;
                break;
            default:
                std::cout << "Invalid method." << std::endl;
        }
    }


    std::cout << n << "-th fibonnaci is: " << r << std::endl;
    std::cout << "Chosen method: ";

    if(input == 1) {
        std::cout << "recursion" << std::endl;
    }else{
        std::cout << "iteration" << std::endl;
    }
        std::cout << std::setprecision(6) << std::fixed << "Time taken: " << ((double)(clock()-t)) / CLOCKS_PER_SEC << " Seconds" << std::endl;
    return 0;
}