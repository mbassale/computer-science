//
// Created by Marco Bassaletti on 28-02-21.
//
#include <iostream>

using namespace std;

namespace mbassale {
    template<typename T>
    bool is_prime(T x) {
        if (x < 2) return false;
        for (T i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
}

int main() {
    for (auto i = 0; i < 100; i++) {
        cout << boolalpha << "is_prime(" << i << ") = " << mbassale::is_prime(i) << endl;
    }
    return 0;
}