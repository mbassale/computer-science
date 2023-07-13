#pragma once

#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

template <typename T>
std::string vector2str(const std::vector<T>& items,
                       size_t maxCount = SIZE_T_MAX) {
  std::ostringstream ss;
  int upperBound = std::min(items.size(), maxCount);
  for (size_t i = 0; i < upperBound; i++) {
    ss << items[i];
    if (i < upperBound - 1) {
      ss << ",";
    }
  }
  return ss.str();
}