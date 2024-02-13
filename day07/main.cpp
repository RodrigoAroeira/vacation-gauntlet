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

void insertion_sort(int* arr, int size){ // a more concise implementation can be done
    std::cout << "Sorting (Insertion sort)" << std::endl;
    int i = 0, j = 0, hold = 0;
    for (i = 1; i < size; ++i) { //second element first
        hold = arr[i]; //checks an element, holds it
        for (j = i-1; j >= 0; --j) { //looks back, checks if the held element is greater
            if(arr[j] > hold){
                arr[j+1] = arr[j]; //if it is, pushes everything to the left of held element to the right
            }else{
                break; //if it isn't, breaks, otherwise will keep subtracting from j
            }
        }
        arr[j+1] = hold; //takes j+1 (j can and will be -1 in case of a least element of the array) and equals it to hold, inserting hold into the position j stopped comparing at
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