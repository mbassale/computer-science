#include <iostream>
#include <algorithm>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
class MergeSort {
public:

    MergeSort() {};

    void sort(T& arr) {
        T aux;
        aux.resize(arr.size());
        merge_sort(aux, arr, 0, arr.size() - 1);
    }

private:
    void merge_sort(T& aux, T& arr, size_t left, size_t right) {
        if (left >= right) return;
        size_t mid = left + std::floor((right - left) / 2.0); // prevent overflow.
        merge_sort(aux, arr, left, mid);
        merge_sort(aux, arr, mid + 1, right);
        merge(aux, arr, left, mid, right);
    }
 
    void merge(T& aux, T& arr, size_t left, size_t mid, size_t right) {
        // copy original data into aux array.
        for (auto idx = left; idx <= right; idx++)
            aux[idx] = arr[idx];
        // merge in arr
        auto i = left;
        auto j = mid + 1;
        for (auto k = left; k <= right; k++) {
            if (i > mid) arr[k] = aux[j++]; // left subarray exhausted, take right subarray.
            else if (j > right) arr[k] = aux[i++]; // right subarray exhausted, take left subarray.
            else if (aux[j] < aux[i]) arr[k] = aux[j++];
            else arr[k] = aux[i++];
        }
    }
};

int main(int argc, char* argv[]) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "Merge Sort." << std::endl;

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
    MergeSort<std::vector<long>> merge_sort;
    merge_sort.sort(numbers);
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
            return EXIT_FAILURE;
        }
    }
    std::cout << "Done." << std::endl;

    return EXIT_SUCCESS;
}