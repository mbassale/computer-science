#include <iostream>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
class ShellSort {
public:
    ShellSort() {};

    void sort(T& arr) {
        size_t len = arr.size();
        size_t h = 1;
        while (h < len / 3) h = 3 * h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
        while (h >= 1) {
            for (size_t i = h; i < len; i++) {
                for (size_t j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                    swap(arr, j, j - h);
            }
            h = h / 3;
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

    std::cout << "Shell Sort." << std::endl;

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
    ShellSort<std::vector<long>> shell_sort;
    shell_sort.sort(numbers);
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