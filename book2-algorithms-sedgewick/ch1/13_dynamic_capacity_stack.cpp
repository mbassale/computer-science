#include <iostream>
#include <memory>
#include <string>

template<typename T>
class DynamicCapacityStack {
private:
    static constexpr size_t initial_capacity = 10;
    std::unique_ptr<T[]> data;
    size_t capacity{ initial_capacity };
    size_t data_size{};

public:
    DynamicCapacityStack() {
        data = std::unique_ptr<T[]>( new T[initial_capacity] );
    }

    [[nodiscard]] bool empty() { return data_size == 0; }
    [[nodiscard]] size_t size() { return data_size; }
    [[nodiscard]] size_t get_capacity() { return capacity; }

    void push(const T& item) { 
        if (data_size == capacity) resize(2 * data_size);
        data[data_size++] = item; 
    }
    T pop() { 
        auto item = data[--data_size];
        if (data_size > 0 && data_size == capacity / 4) resize(capacity / 2);
        return item;
    }

private:
    void resize(size_t new_capacity) {
        std::unique_ptr<T[]> new_data{ new T[new_capacity] };
        for (size_t i = 0; i < data_size; i++)
            new_data[i] = data[i];
        data = std::move(new_data);
        capacity = new_capacity;
    }
};

int main() {
    using namespace std;
    cout << "DynamicCapacityStack" << endl;
    
    DynamicCapacityStack<std::string> s{};
    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        auto num_str = std::to_string(i);
        s.push(num_str);
        cout << "Pushed: " << num_str << " StackSize: " << s.size() << " StackCapacity: " << s.get_capacity() << endl;
    }

    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        auto num_str = s.pop();
        cout << "Poped: " << num_str << " StackSize: " << s.size() << " StackCapacity: " << s.get_capacity() << endl;
    }

    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    return 0;
}