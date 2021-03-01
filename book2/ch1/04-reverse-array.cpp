//
// Created by Marco Bassaletti on 28-02-21.
//
#include <iostream>
#include <array>

using namespace std;

namespace mbassale {
    template<typename T, size_t C>
    void reverse_array(array<T, C>& a) {
        for (auto i = 0; i < C/2; i++) {
            auto tmp = a[i];
            a[i] = a[C - i - 1];
            a[C - i - 1] = tmp;
        }
    }
}

int main() {
    auto a1 = array<int, 10>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Original array: ";
    for (auto n : a1) {
        cout << n << " ";
    }
    cout << endl;
    mbassale::reverse_array(a1);
    cout << "Reversed array: ";
    for (auto n : a1) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}