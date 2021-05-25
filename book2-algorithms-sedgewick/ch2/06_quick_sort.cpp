#include <iostream>
#include <algorithm>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
class QuickSort {
public:

    QuickSort() {};

    void sort(T& arr) {
        sort(arr, 0, arr.size() - 1);
    }

private:

    void sort(T& arr, size_t left, size_t right) {
        if (left >= right) return;
        if (left < 0 || right >= arr.size()) return;
        size_t j = partition(arr, left, right);
        sort(arr, left, j - 1);
        sort(arr, j + 1, right);
    }

    size_t partition(T& arr, size_t left, size_t right) {
        auto i = left;
        auto j = right + 1;
        auto v = arr[left];
        while (true) {
            while (arr[++i] < v) if (i >= right) break;
            while (v < arr[--j]) if (j <= left) break;
            if (i >= j) break;
            swap(arr, i, j);
        }
        swap(arr, left, j);
        return j;
    }

    void swap(T& arr, size_t i, size_t j) {
        auto tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main(int argc, char* argv[]) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "Quicksort." << std::endl;

    if (argc <= 1) {
        std::cerr << "Missing number of elements." << std::endl;
        return EXIT_FAILURE;
    }

    size_t numbers_length = std::stoi(argv[1]);
    std::cout << "Number of Elements: " << numbers_length << std::endl;

    std::cout << "Generating data... " << std::flush;
    std::vector<long> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <size_t> dist(0, 1000000);
    while (numbers_length > 0) {
        numbers.push_back(dist(gen));
        numbers_length--;
    }
    std::cout << "Done." << std::endl;

    if (numbers.size() < 100) {
        auto it = numbers.begin();
        std::cout << "Numbers: ";
        while (it != numbers.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }

    std::cout << "Sorting... " << std::flush;
    auto t1 = high_resolution_clock::now();
    QuickSort<std::vector<long>> quick_sort;
    quick_sort.sort(numbers);
    auto t2 = high_resolution_clock::now();
    std::cout << "Done." << std::endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "Running Time: " << running_time << "ms" << std::endl;

    if (numbers.size() < 100) {
        auto it = numbers.begin();
        std::cout << "Numbers: ";
        while (it != numbers.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }

    std::cout << "Checking... " << std::flush;
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] > numbers[i + 1]) {
            std::cerr << "Bad sorting: " << numbers[i] << ", " << numbers[i + 1] << std::endl;
        }
    }
    std::cout << "Done." << std::endl;

    return EXIT_SUCCESS;
}