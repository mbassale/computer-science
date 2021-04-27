//
// Created by Marco Bassaletti on 28-02-21.
//
#include <iostream>
#include <cmath>

using namespace std;

namespace mbassale {
    double sqrt(double x) {
        if (x < 0.0) return NAN;
        double eps = 1e-15;
        double t = x;
        while (std::abs(t - x / t) > eps * t) {
            t = (x/t + t) / 2.0;
        }
        return t;
    }
}

int main() {
    for (auto i = 0; i < 100; i++) {
        auto root = mbassale::sqrt(i);
        cout << "sqrt(" << i << ") = " << root << " delta = " << i - root*root << endl;
    }
    return 0;
}