
#include "AllocationsTracker.hpp"

#include <cmath>
#include <csetjmp>
#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include <vector>

AllocationsTracker &tracker = AllocationsTracker::getInstance();

// needed so structures that automatically allocate memory don't recurse or smth
bool insideNewOperator = false;

void *operator new(std::size_t size) {
  if (insideNewOperator) {
    return malloc(size);
  }

  insideNewOperator = true;

  void *ptr = malloc(size);
  if (!ptr) {
    insideNewOperator = false;
    throw std::bad_alloc();
  }

  tracker.add(ptr, size);

  std::cout << "Allocated " << size << " bytes at " << ptr << std::endl;

  insideNewOperator = false;
  return ptr;
}

void operator delete(void *ptr) noexcept {
  if (ptr) {
    tracker.remove(ptr);
    free(ptr);
    std::cout << "Deallocated memory at " << ptr << std::endl;
  }
}

void reportLeaks() { tracker.reportLeaks(); }

int main(int argc, char **argv) {
  int size = argc > 1 ? std::stoi(argv[1]) : 8;
  std::vector<long double *> randomAllocations;

  for (int i = 0; i < size; i++)
    randomAllocations.push_back(new long double);

  reportLeaks();

  return 0;
  // For some reason i'm getting segfault, probably when vector or tracker map
  // are being deleted, but it mostly works. I'll eventually figure out
}
