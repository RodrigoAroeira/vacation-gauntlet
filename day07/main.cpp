// failed compiles: 
// failed runs: 
// time taken: 03:12

#include <iostream>
#include <string>
#include <cstring>

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
    int j = 0, hold = 0;
    for (int i = 1; i < size; ++i) { //second element first
        hold = arr[i]; //checks an element, holds it
        for (j = i-1; j >= 0 && arr[j] > hold; --j) { //looks back, checks if the held element is greater
            arr[j+1] = arr[j]; //if it is, pushes everything to the left of held element to the right
        }
        arr[j+1] = hold; //takes j+1 (j can and will be -1 in case of a least element of the array) and equals it to hold, inserting hold into the position j stopped comparing at
    }
}

void merge(int* arr1, int start, int mid, int end){
    int arr[end-start];
    int i = start, j = mid, a = 0;
    while (i < mid && j < end){ //actual merging
        if(arr[i] < arr[j]){
            arr[a] = arr[i];
            i++;
        }else{
            arr[a] = arr[j];
            j++;
        }
        a++;
    }
    while(i<mid){//array dump
        arr[a] = arr[i];
        i++;
        a++;
    }
    while (j<end){ //array dump
        arr[a] = arr[j];
        j++;
        a++;
    }
    memcpy(&arr1[start], arr, end-start); //not necessarily start = arr1[0]
}

void merge_sort(int* arr, int start, int end){ //recursive

    if (end-start > 1) // if the indexes are the same, subarray is 1-sized
        return;

    int mid = start + (end - start)/2; // gets middle value during recursions
    merge_sort(arr, start, mid); // merge sorts left half
    merge_sort(arr, mid, end); // merge sorts right half
    merge(arr, start, mid, end);
}


int main(){
    int arr[] = {3, 2, 5, 9, 8, 4, 7, 1, 6};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr, size);
    insertion_sort(arr, size);
    print_array(arr, size);
    return 0;
}