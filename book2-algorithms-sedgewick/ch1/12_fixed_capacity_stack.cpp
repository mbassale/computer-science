#include <iostream>
#include <memory>
#include <string>

#define MAX_CAPACITY 100

template<typename T>
class FixedCapacityStack {
private:
    std::unique_ptr<T[]> data;
    size_t data_size{};

public:
    FixedCapacityStack() {
        data = std::unique_ptr<T[]>( new T[MAX_CAPACITY] );
    }

    [[nodiscard]] bool empty() { return data_size == 0; }
    [[nodiscard]] size_t size() { return data_size; }

    void push(const T& item) { data[data_size++] = item; }
    T pop() { return data[--data_size]; }
};

int main() {
    using namespace std;
    cout << "FixedCapacityStack" << endl;
    
    FixedCapacityStack<std::string> s{};
    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        auto num_str = std::to_string(i);
        s.push(num_str);
        cout << "Pushed: " << num_str << " StackSize: " << s.size() << endl;
    }

    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        auto num_str = s.pop();
        cout << "Poped: " << num_str << " StackSize: " << s.size() << endl;
    }

    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    return 0;
}