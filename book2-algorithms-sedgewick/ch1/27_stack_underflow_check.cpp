#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

int main(int argc, char* argv[]) {
    using namespace std;
    cout << "Stack Check Problem - Linear Time Solution" << endl;

    int size = 0;
    for (int i = 1; i < argc; i++) {
        auto num = stoi(argv[i]);
        if (num >= 0) size++;
        else size--;
        if (size < 0) {
            cout << "Stack Underflow!" << endl;
            return EXIT_SUCCESS;
        }
    }

    cout << "Stack OK!" << endl;
    return EXIT_SUCCESS;
}
