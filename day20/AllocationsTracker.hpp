#pragma once
#include <cstdlib>
#include <iostream>
#include <unordered_map>

class AllocationsTracker {
public:
  static AllocationsTracker &getInstance() {
    static AllocationsTracker instance;
    return instance;
  }

  void add(void *ptr, std::size_t size) { allocations[ptr] = size; }

  void remove(void *ptr) { allocations.erase(ptr); }

  void reportLeaks() const {
    if (allocations.empty()) {
      std::cout << "No memory leaks detected!" << std::endl;
    } else {
      std::cout << allocations.size() << " memory leaks detected:" << std::endl;

      for (const auto &entry : allocations) {
        std::cout << "Leaked " << entry.second << " bytes at " << entry.first
                  << std::endl;
      }
    }
  }

private:
  std::unordered_map<void *, std::size_t> allocations;

  AllocationsTracker() = default;
  ~AllocationsTracker() = default;

  AllocationsTracker(const AllocationsTracker &) = delete;
  AllocationsTracker &operator=(const AllocationsTracker &) = delete;
};
