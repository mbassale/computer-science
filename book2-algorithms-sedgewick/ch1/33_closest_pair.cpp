#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

std::pair<long, long> find_closest_pair(std::vector<long> &numbers) {
    long min_distance = LONG_MAX;
    std::pair<long, long> closest_pair{0, 0};
    std::sort(numbers.begin(), numbers.end());
    auto current = numbers.begin();
    auto last = numbers.end() - 1;
    while (current < last) {
        auto next = current + 1;
        auto distance = *next - *current;
        if (distance < min_distance) {
            closest_pair.first = *current;
            closest_pair.second = *next;
            min_distance = distance;
        }
        current++;
    }
    return closest_pair;
}

int main(int argc, char *argv[]) {
    using namespace std;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    cout << "Closest Pair Problem." << endl;

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
    auto closest_pair = find_closest_pair(numbers);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    auto diff = closest_pair.second - closest_pair.first;
    cout << "Closest Pair: " << closest_pair.first << "," << closest_pair.second << " Diff: " << diff << " Running Time: " << running_time
         << "ms" << endl;
    return EXIT_SUCCESS;
}
