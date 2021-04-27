//
// Created by Marco Bassaletti on 01-03-21.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
struct WeightedQuickUnion {

    WeightedQuickUnion(size_t N) : N{N } {
        id.resize(N);
        id_sizes.resize(N);
        for (auto i = 0; i < N; i++) {
            id[i] = i;
            id_sizes[i] = 1;
        }
    }

    void make_union(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (id_sizes[i] < id_sizes[j]) {
            id[i] = j;
            id_sizes[j] += id_sizes[i];
        } else {
            id[j] = i;
            id_sizes[i] += id_sizes[j];
        }
    }

    bool is_connected(int p, int q) {
        return root(p) == root(q);
    }

    void dump() {
        cout << "id:       ";
        for (T i : id) {
            cout << i << " ";
        }
        cout << endl;
        cout << "id sizes: ";
        for (T i : id_sizes) {
            cout << i << " ";
        }
        cout << endl;
    }

private:
    int root(T i) {
        while (i != id[i]) {
            auto parent = id[i];
            id[i] = id[parent]; // flatten the tree
            i = id[i];
        }
        return i;
    }

    size_t N{};
    vector<T> id;
    vector<size_t> id_sizes;
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
    WeightedQuickUnion<int> quick_union{N };
    while (!connect_model.eof()) {
        int p, q;
        connect_model >> p >> q;
        cout << "union(" << p << "," << q << ")" << endl;
        quick_union.make_union(p, q);
        cout << boolalpha << "is_connected(" << p << "," << q << ") = " << quick_union.is_connected(p, q) << endl;
    }
    quick_union.dump();
    return 0;
}
