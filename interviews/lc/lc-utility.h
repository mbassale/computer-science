#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::ostringstream;
using std::pair;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

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
