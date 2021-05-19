#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <chrono>

size_t four_sum(std::vector<long> &numbers) {
    size_t sum_count = 0;
    // n * log(n) sorting.
    std::sort(numbers.begin(), numbers.end());

    auto it1 = numbers.begin();
    while (it1 != numbers.end()) {
        auto it2 = it1 + 1;
        while (it2 != numbers.end()) {
            auto it3 = it2 + 1;
            while (it3 != numbers.end()) {
                // perform binary search from this number onwards to prevent double counting.
                auto num1 = *it1;
                auto num2 = *it2;
                auto num3 = *it3;
                auto search_num = -num1 - num2 - num3;
                if (std::binary_search(it3, numbers.end(), search_num)) {
                    sum_count++;
                }
                it3++;
            }
            it2++;
        }
        it1++;
    }
    return sum_count;
}

int main(int argc, char *argv[]) {
    using namespace std;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    cout << "Four Sum Problem with Binary Search." << endl;

    if (argc < 2) {
        cerr << "Missing data filename." << endl;
        return EXIT_FAILURE;
    }

    cout << "Loading data." << endl;

    ifstream in_file(argv[1], ios::in);
    if (!in_file.is_open()) {
        cerr << "Cannot open data filename: " << argv[1] << endl;
        return EXIT_FAILURE;
    }

    vector<long> numbers;
    string line;
    while (getline(in_file, line)) {
        auto number = stol(line);
        numbers.push_back(number);
    }

    cout << "Read " << numbers.size() << " integers." << endl;

    cout << "Calculating... " << flush;
    auto t1 = high_resolution_clock::now();
    auto sum_count = four_sum(numbers);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Number of Zero Four Sums: " << sum_count << " Running Time: " << running_time << "ms" << endl;
    return EXIT_SUCCESS;
}
