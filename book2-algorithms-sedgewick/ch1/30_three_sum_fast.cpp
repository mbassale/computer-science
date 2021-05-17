#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

size_t three_sum_fast(std::vector<long> &numbers) {
    size_t sum_count = 0;
    // n * log(n) sorting.
    std::sort(numbers.begin(), numbers.end());
    auto it = numbers.begin();
    while (it != numbers.end()) {
        auto it2 = it + 1;
        while (it2 != numbers.end()) {
            // perform binary search from this number onwards to prevent double counting.
            auto num1 = *it;
            auto num2 = *it2;
            auto search_num = -num1 - num2;
            if (std::binary_search(it2, numbers.end(), search_num)) {
                sum_count++;
            }
            it2++;
        }
        it++;
    }
    return sum_count;
}

int main(int argc, char *argv[]) {
    using namespace std;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    cout << "Three Sum Problem with Binary Search." << endl;

    if (argc < 2) {
        cerr << "Missing data filename." << endl;
        return EXIT_FAILURE;
    }

    cout << "Loading data." << endl;

    stringstream data_filename;
    data_filename << "./data/" << argv[1];
    ifstream in_file(data_filename.str(), ios::in);
    if (!in_file.is_open()) {
        cerr << "Cannot open data filename: " << data_filename.str() << endl;
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
    auto sum_count = three_sum_fast(numbers);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Number of Zero Three Sum: " << sum_count << " Running Time: " << running_time << "ms" << endl;
    return EXIT_SUCCESS;
}
