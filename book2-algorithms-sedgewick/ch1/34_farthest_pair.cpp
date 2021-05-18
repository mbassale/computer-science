#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

std::pair<long, long> find_farthest_pair(std::vector<long> &numbers) {
    std::pair<long, long> farthest_pair{0, 0};
    long min_val = LONG_MAX;
    long max_val = LONG_MIN;
    auto it = numbers.begin();
    while (it != numbers.end()) {
        min_val = std::min(min_val, *it);
        max_val = std::max(max_val, *it);
        it++;
    }
    farthest_pair.first = min_val;
    farthest_pair.second = max_val;
    return farthest_pair;
}

int main(int argc, char *argv[]) {
    using namespace std;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    cout << "Farthest Pair Problem." << endl;

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
    auto farthest_pair = find_farthest_pair(numbers);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    auto diff = farthest_pair.second - farthest_pair.first;
    cout << "Farthest Pair: " << farthest_pair.first << "," << farthest_pair.second << " Diff: " << diff
         << " Running Time: " << running_time
         << "ms" << endl;
    return EXIT_SUCCESS;
}
