#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <chrono>
#include <random>

size_t find_local_minimum(const std::vector <uint32_t> &numbers, size_t left, size_t right) {
    if (left >= right) return -1;

    size_t mid = std::floor((right - left) / 2.0) + left;
    if (mid == 0) {
        if (numbers[mid] < numbers[mid + 1]) return mid;
    } else if (mid == numbers.size() - 1) {
        if (numbers[mid] < numbers[mid - 1]) return mid;
    } else {
        if (numbers[mid] < numbers[mid - 1] && numbers[mid] < numbers[mid + 1]) return mid;
    }

    auto left_min = find_local_minimum(numbers, left, mid - 1);
    if (left_min >= 0) return left_min;
    auto right_min = find_local_minimum(numbers, mid + 1, right);
    return right_min;
}

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "Find Local Minimum with Binary Search." << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <uint32_t> dist(0, 1000000);

    std::vector <uint32_t> numbers;
    size_t arr_size = 1000000;
    while (arr_size > 0) {
        numbers.push_back(dist(gen));
        arr_size--;
    }

    auto t1 = high_resolution_clock::now();
    auto loc_min = find_local_minimum(numbers, 0, numbers.size() - 1);
    auto t2 = high_resolution_clock::now();

    auto running_time = duration_cast<milliseconds>(t2 - t1);
    std::cout << "Local Minimum: ";
    auto start_index = loc_min > 2 ? loc_min - 2 : 0;
    auto end_index = loc_min < numbers.size() - 2 ? loc_min + 2 : numbers.size() - 1;
    for (size_t index = start_index; index <= end_index; index++) {
        if (index == loc_min)
            std::cout << "|" << numbers[loc_min] << "| ";
        else
            std::cout << numbers[index] << " ";
    }
    std::cout << "Running Time: " << running_time.count() << "ms" << std::endl;

    return EXIT_SUCCESS;
}
