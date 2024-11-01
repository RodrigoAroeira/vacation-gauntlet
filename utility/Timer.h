#pragma once

#include <chrono>
#include <iostream>
#include <sstream>
#include <type_traits>

// Constexpr function to get the unit string
template <typename T>
static constexpr const char *getUnitString() {
  if constexpr (std::is_same_v<T, std::chrono::nanoseconds>) {
    return "ns";
  } else if constexpr (std::is_same_v<T, std::chrono::microseconds>) {
    return "\u03BCs";
  } else if constexpr (std::is_same_v<T, std::chrono::milliseconds>) {
    return "ms";
  } else if constexpr (std::is_same_v<T, std::chrono::seconds>) {
    return "s";
  } else if constexpr (std::is_same_v<T, std::chrono::minutes>) {
    return "min";
  } else if constexpr (std::is_same_v<T, std::chrono::hours>) {
    return "h";
  } else {
    return "";
  }
}

namespace utils {
template <typename toDur = std::chrono::milliseconds>
class Timer {
public:
  Timer(bool scoped) : mScoped(scoped), mDuration(0), mStarted(false) {
    if (mScoped)
      start();
  }

  Timer() : Timer(true) {}

  void start() {
    mStartTP = std::chrono::high_resolution_clock::now();
    mStarted = true;
  }
  void end() {
    if (!mStarted)
      return;

    auto endTP = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<toDur>(mStartTP)
                     .time_since_epoch()
                     .count();

    auto end =
        std::chrono::time_point_cast<toDur>(endTP).time_since_epoch().count();

    mDuration = end - start;

    if (mScoped)
      std::cout << durationString() << std::endl;

    mStarted = false;
  }

  ~Timer() {
    if (mStarted)
      end();
  }

  std::string durationString() {
    std::stringstream ss;
    ss << mDuration << getUnitString<toDur>();
    return ss.str();
  }

  double duration() { return mDuration; }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> mStartTP;
  bool mStarted;
  bool mScoped;
  double mDuration;
};
} // namespace utils
