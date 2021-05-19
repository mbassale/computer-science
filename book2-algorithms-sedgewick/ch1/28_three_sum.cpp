#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

size_t three_sum(const std::vector<long> &numbers) {
    size_t sum_count = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            for (size_t k = j + 1; k < numbers.size(); k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 0)
                    sum_count++;
            }
        }
    }
    return sum_count;
}

int main(int argc, char *argv[]) {
    using namespace std;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    cout << "Three Sum Problem." << endl;

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
    auto sum_count = three_sum(numbers);
    auto t2 = high_resolution_clock::now();
    cout << "Done." << endl;
    auto running_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Number of Zero Three Sums: " << sum_count << " Running Time: " << running_time << "ms" << endl;
    return EXIT_SUCCESS;
}
