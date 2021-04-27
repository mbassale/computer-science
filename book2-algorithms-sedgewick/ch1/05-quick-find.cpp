//
// Created by Marco Bassaletti on 28-02-21.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
struct QuickFind {
    QuickFind(size_t N) : N{ N } {
        id.resize(N);
        for (auto i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    bool is_connected(T p, T q) {
        return id[p] == id[q];
    }

    bool make_union(T p, T q) {
        auto idp = id[p];
        auto idq = id[q];
        for (auto i = 0; i < N; i++) {
            if (id[i] == idp) id[i] = idq;
        }
    }

    void dump() {
        cout << "id: ";
        for (T i : id) {
            cout << i << " ";
        }
        cout << endl;
    }

    size_t N{};
    vector<T> id;
};

int main() {
    ifstream connect_model{ "../ch1/data/01-union-find.txt", std::ios::in };
    if (!connect_model.is_open()) {
        cout << "failed to open" << endl;
        exit(1);
    }
    size_t N{};
    connect_model >> N;
    cout << "Number of nodes: " << N << endl;
    QuickFind<int> quick_find{ N };
    while (!connect_model.eof()) {
        int p, q;
        connect_model >> p >> q;
        cout << "union(" << p << "," << q << ")" << endl;
        quick_find.make_union(p, q);
        cout << boolalpha << "is_connected(" << p << "," << q << ") = " << quick_find.is_connected(p, q) << endl;
    }
    quick_find.dump();
    return 0;
}