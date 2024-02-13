// failed compiles: 
// failed runs: 
// time taken: 03:12

#include <iostream>

void print_array(int* arr, int size){
    std::cout << "Array: " << "\x1b[33m" << "[";
    std::cout << arr[0];
    for (int i = 1; i < size; i++) {
        std::cout << ", " << arr[i];
    }
    std::cout << "]" << "\x1b[39m" << std::endl;
}

void insertion_sort(int* arr, int size){
    std::cout << "Sorting (Insertion sort)" << std::endl;
    int i = 0, j = 0, hold = 0;
    for (i = 1; i < size; ++i) {
        hold = arr[i];
        for (j = i-1; j >= 0; --j) {
            if(arr[j] > hold){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = hold;
    }
}


int main(){
    int arr[] = {3, 2, 5, 9, 8, 4, 7, 1, 6};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr, size);
    insertion_sort(arr, size);
    print_array(arr, size);
    return 0;
}