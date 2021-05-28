#include <iostream>
#include <algorithm>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
void print_numbers(const T& numbers) {
    if (numbers.size() < 100) {
        auto it = numbers.begin();
        std::cout << "Numbers: ";
        while (it != numbers.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "STL make_heap Experiments." << std::endl;
    
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

    print_numbers(numbers);
    
    std::cout << "Make Heap... " << std::flush;
    std::make_heap(numbers.begin(), numbers.end());
    std::cout << "Done." << std::endl;

    print_numbers(numbers);

    while (numbers.size() > 0) {
        auto max_num = numbers.front();
        std::pop_heap(numbers.begin(), numbers.end());
        numbers.pop_back();
        std::cout << "Max: " << max_num << " Size: " << numbers.size() << std::endl;
    }

    return EXIT_SUCCESS;
}