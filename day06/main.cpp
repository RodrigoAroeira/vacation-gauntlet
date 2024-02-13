// failed compiles: 
// failed runs: 
// time taken: 20:00

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using std::vector;

int binary_search(const int* arr, int size, int target){ // has to be a sorted array in ascending order
    int L = 0;
    int R = size-1;
    int mid, up, lw;
    while (L < R){
        mid = (L + R)/2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target){
            R = mid-1;
        }else{
            L = mid+1;
        }
    }

    if(arr[mid] > target){
        up = arr[mid];
    }else{
        up = arr[mid+1];
    }

    if(arr[mid] < target){
        lw = arr[mid];
    }else{
        lw = arr[mid-1];
    }

    if(arr[0] > target) {
        lw = -1;
        up = arr[0];
    }
    if(arr[size-1] < target) {
        lw = arr[size-1];
        up = -1;
    }

    std::cout << "Lower bound: " << lw << "\nUpper bound: " << up << std::endl;
    return -1; // if not found
}

int binary_search(const vector<int>* vec, int target){
    int n = vec->size();
    int L = 0;
    int R = n - 1;
    int mid, up, lw;
    while(L <= R){
        mid = (L+R)/2;

        if (vec->at(mid) == target){
            return mid;
        }
        if (vec->at(mid) == target) {
            return mid;
        }
        if (vec->at(mid) > target){
            R = mid-1;
        }else{
            L = mid+1;
        }
    }
    if(vec->at(mid) > target){
        up = vec->at(mid);
    }else{
        up = vec->at(mid+1);
    }

    if(vec->at(mid) < target){
        lw = vec->at(mid);
    }else{
        lw = vec->at(mid-1);
    }

    if(vec->at(0) > target) {
        lw = -1;
        up = vec->at(0);
    }
    if(vec->at(vec->size()-1) < target) {
        lw = vec->at(vec->size()-1);
        up = -1;
    }
    std::cout << "Lower bound: " << lw << "\nUpper bound: " << up << std::endl;
    return -1; // if not found
}

vector<int>* generate_vector(int size){
    auto vec = new std::vector<int>();

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    std::cout << "Generated vector: \n" << "\x1b[33m" << "<";
    for (int i = 0; i < size; i++){
        int num = dist(mt);
        std::cout << num;
        if (i != size-1)
            std::cout << ", ";
        vec->push_back(num);
    }
    std::cout << ">" << "\x1b[39m" << std::endl;

    std::sort(vec->begin(), vec->end()); // the generated vector is already sorted

    return vec;
}

int* generate_array(int size){

    int* arr = new int [size];

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    std::cout << "Generated array: \n" << "\x1b[33m" << "[";
    for (int i = 0; i < size; i++){
        int num = dist(mt);
        std::cout << num;
        if (i != size-1)
            std::cout << ", ";
        arr[i] = num;
    }
    std::cout << "]" << "\x1b[39m" << std::endl;

    std::sort(arr, arr+size);

    return arr;
}


int main(int argc, char* argv[]){
    int size, target, pos;
    if (argc > 1){
        size = std::stoi(argv[1]);
    } else {
        std::cout << "Input the array size: ";
        std::cin >> size;
    }

    std::cout << "Type in a number to find inside the array: " << std::endl;
    std::cin >> target;

    int* arr = generate_array(size);

    std::cout << "Sorted array: \n" << "\x1b[33m" << "[";
    for (int i = 0; i < size-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size-1];
    std::cout << "]" << "\x1b[39m" << std::endl;


    pos = binary_search(arr, size, target);
    if(pos != -1)
        std::cout << "Element found in position " << pos << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::vector<int>* vec = generate_vector(size);

    std::cout << "Sorted vector: \n" << "\x1b[33m" << "<";
    for (int i : *vec) {
        std::cout << i << ", ";
    }
    std::cout << vec->back();
    std::cout << ">" << "\x1b[39m" << std::endl;

    pos = binary_search(vec, target);
    if(pos != -1)
        std::cout << "Element found in position " << pos << std::endl;
    else
        std::cout << "Element not found" << std::endl;

}