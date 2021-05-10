#include <iostream>
#include <string>
#include <vector>
#include <cmath>

template<typename T>
class Bag {
private:
    std::vector<T> data{};

public:
    Bag() = default;

    void add(T& item) {
        data.push_back(item);
    }

    auto size() {
        return data.size();
    }

    auto begin() {
        return data.begin();
    }

    auto end() {
        return data.end();
    }
};

int main() {
    using namespace std;

    Bag<int> bag{};
    cout << "Bag Demo" << endl;
    while (true) {
        string line;
        getline(cin, line);
        if (line.size() == 0) break;
        int num = stoi(line);
        bag.add(num);
    }

    double sum = 0;
    auto it = bag.begin();
    while (it != bag.end()) {
        sum += *it;
        it++;
    }
    double mean = sum / bag.size();

    sum = 0;
    it = bag.begin();
    while (it != bag.end()) {
        sum += pow(*it - mean, 2);
        it++;
    }
    double stddev = sqrt(sum / (bag.size() - 1));

    cout << "Mean: " << mean << endl;
    cout << "Stddev: " << stddev << endl;

    return 0;
}