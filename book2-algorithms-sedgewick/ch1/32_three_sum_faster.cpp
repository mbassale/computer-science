#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <chrono>

size_t two_sum_k(std::vector<long>::iterator begin, std::vector<long>::iterator end, long k) {
    size_t sum_count = 0;
    std::unordered_set<long> hashset{ *begin };

    auto it = begin + 1;
    while (it < end) {
        auto num = *it;
        auto find_it = hashset.find(k - num);
        if (find_it != hashset.end()) {
            sum_count++;
        } else
            hashset.insert(num);
        it++;
    }

    return sum_count;
}

size_t three_sum_k(std::vector<long>::iterator begin, std::vector<long>::iterator end, long k) {
    size_t sum_count = 0;

    auto it = begin + 1;
    while (it < end) {
        auto diff = k - *it;
        auto num_pairs = two_sum_k(it + 1, end, diff);
        if (num_pairs > 0)
            sum_count += num_pairs;
        it++;
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
    if (argc < 3) {
        cerr << "Missing target sum K." << endl;
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
    long k = stol(argv[2]);
    cout << "Using K=" << k << endl;

    cout << "Calculating... " << flush;
    auto t1 = high_resolution_clock::now();
    auto sum_count = three_sum_k(numbers.begin(), numbers.end(), k);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Number of Zero Three Sums: " << sum_count << " Running Time: " << running_time << "ms" << endl;
    return EXIT_SUCCESS;
}
