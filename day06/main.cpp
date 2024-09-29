// failed compiles:
// failed runs:
// time taken: 1 hour

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using std::vector;

int binary_search(const int *arr, int size, int target) {
  int L = 0;
  int R = size - 1;
  int mid, up, lw;

  while (L <= R) {
    mid = (L + R) / 2;

    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] > target) {
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }

  // Handle case when target is not found
  if (L >= size) {
    // Target is larger than all elements
    lw = arr[size - 1];
    up = -1;
  } else if (R < 0) {
    // Target is smaller than all elements
    lw = -1;
    up = arr[0];
  } else {
    // General case when target is between elements
    lw = arr[R];
    up = arr[L];
  }

  std::cout << "Lower bound: " << lw << "\nUpper bound: " << up << std::endl;
  return -1; // Target not found
}

int binary_search(const std::vector<int> &vec, int target) {
  int L = 0;
  int R = vec.size() - 1;
  int mid, up, lw;

  while (L <= R) {
    mid = (L + R) / 2;

    if (vec.at(mid) == target) {
      return mid;
    }
    if (vec.at(mid) > target) {
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }

  // Handle the case when the target is not found
  if (L >= vec.size()) {
    // Target is greater than all elements
    lw = vec.at(vec.size() - 1);
    up = -1;
  } else if (R < 0) {
    // Target is smaller than all elements
    lw = -1;
    up = vec.at(0);
  } else {
    // General case when target is between elements
    lw = vec.at(R);
    up = vec.at(L);
  }

  std::cout << "Lower bound: " << lw << "\nUpper bound: " << up << std::endl;
  return -1; // target not found
}

vector<int> generate_vector(int size) {
  std::vector<int> vec;

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1, 10000);

  std::cout << "Generated vector: \n"
            << "\x1b[33m" << "<";
  for (int i = 0; i < size; i++) {
    int num = dist(mt);
    std::cout << num;
    if (i != size - 1)
      std::cout << ", ";
    vec.push_back(num);
  }
  std::cout << ">" << "\x1b[39m" << std::endl;

  std::sort(vec.begin(), vec.end()); // the generated vector is already sorted

  return vec;
}

int *generate_array(int size) {

  int *arr = new int[size];

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1, 10000);

  std::cout << "Generated array: \n"
            << "\x1b[33m" << "[";

  for (int i = 0; i < size; i++) {
    int num = dist(mt);
    std::cout << num;
    if (i != size - 1)
      std::cout << ", ";
    arr[i] = num;
  }
  std::cout << "]" << "\x1b[39m" << std::endl;

  std::sort(arr, arr + size);

  return arr;
}

int main(int argc, char *argv[]) {
  int size, target, pos;
  if (argc > 1) {
    size = std::stoi(argv[1]);
  } else {
    std::cout << "Input the array size: ";
    std::cin >> size;
  }

  std::cout << "Type in a number to find inside the array: " << std::endl;
  std::cin >> target;

  int *arr = generate_array(size);

  std::cout << "Sorted array: \n"
            << "\x1b[33m" << "[";

  for (int i = 0; i < size - 1; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[size - 1];
  std::cout << "]" << "\x1b[39m" << std::endl;

  pos = binary_search(arr, size, target);
  if (pos != -1)
    std::cout << "Element found in position " << pos << std::endl;
  else
    std::cout << "Element not found" << std::endl;

  std::cout << "---------------------------------------------------------------"
               "-----------------------"
            << std::endl;

  std::vector<int> vec = generate_vector(size);

  std::cout << "Sorted vector: \n"
            << "\x1b[33m" << "<";

  for (int i : vec) {
    std::cout << i << ", ";
  }

  std::cout << vec.back();
  std::cout << ">" << "\x1b[39m" << std::endl;

  pos = binary_search(vec, target);
  if (pos != -1)
    std::cout << "Element found in position " << pos << std::endl;
  else
    std::cout << "Element not found" << std::endl;

  delete arr;
}
