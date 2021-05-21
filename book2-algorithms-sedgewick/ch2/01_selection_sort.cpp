#include <iostream>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
class SelectionSort {
public:
    SelectionSort() {};

    void sort(T& arr) {
        size_t len = arr.size();
        for (size_t i = 0; i < len; i++) {
            auto min_index = i;
            for (size_t j = i + 1; j < len; j++)
                if (arr[j] < arr[min_index]) min_index = j;
            swap(arr, i, min_index);
        }
    }
private:
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

    std::cout << "Selection Sort." << std::endl;

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

    std::cout << "Sorting... " << std::flush;
    auto t1 = high_resolution_clock::now();
    SelectionSort<std::vector<long>> selection_sort;
    selection_sort.sort(numbers);
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