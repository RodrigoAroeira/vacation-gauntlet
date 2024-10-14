#include <cstddef>
#include <cstdlib>
#include <iostream>

static size_t sAllocations = 0;
static size_t sDeletions = 0;

void operator delete(void *ptr) noexcept {
  sDeletions++;
  free(ptr);
}

void *operator new(size_t size) {
  sAllocations++;
  return malloc(size);
}

void reportLeaks() {
  std::cout << sAllocations << " allocations" << std::endl;
  std::cout << sDeletions << " deletions" << std::endl;
  std::cout << sAllocations - sDeletions << " memory leaks detected.\n";
}

int main(int argc, char **argv) {
  auto arr = new int *[15];

  for (int i = 0; i < 5; i++)
    arr[i] = new int;

  delete[] arr;

  reportLeaks();
}
