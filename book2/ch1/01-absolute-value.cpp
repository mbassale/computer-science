//
// Created by Marco Bassaletti on 28-02-21.
//
#include <iostream>
using namespace std;

namespace mbassale {
    template<typename T>
    T abs(T x) {
        if (x < 0) return -x;
        return x;
    }
}

int main() {
    cout << "|-10| " << mbassale::abs(-10) << endl;
    cout << "|10| " << mbassale::abs(10) << endl;
    cout << "|-3.14| " << mbassale::abs(-3.14) << endl;
    cout << "|3.14| " << mbassale::abs(3.14) << endl;

    return 0;
}