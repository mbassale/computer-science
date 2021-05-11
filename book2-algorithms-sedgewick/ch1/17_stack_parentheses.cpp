#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

template<typename T>
class Stack {
private:
    struct Node {
        T item;
        std::shared_ptr<Node> next{};
    };

    std::shared_ptr<Node> _first{};

public:
    Stack() = default;

    void push(const T& item) {
        auto old_first = _first;
        auto new_first = std::make_shared<Node>();
        new_first->item = item;
        new_first->next = old_first;
        _first = new_first;
    }

    T pop() {
        if (!_first) throw std::runtime_error("empty stack.");
        auto val = _first->item;
        _first = _first->next;
        return val;
    }
};

bool is_balanced(const std::string& parentheses) {
    Stack<char> s;
    auto it = parentheses.begin();
    while (it != parentheses.end()) {
        auto c = *it;
        if (c == '(' || c == '[' || c == '{') s.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            auto prev_c = s.pop();
            if (!((prev_c == '(' && c == ')') || (prev_c == '[' && c == ']') || (prev_c == '{' && c == '}'))) return false;
        }
        it++;
    }
    return true;
}

int main() {
    using namespace std;

    cout << "Balance Parentheses Problem." << endl;

    string parentheses = "[()]{}{[()()]()}";
    cout << "IsBalanced(" << parentheses << ")? " << (is_balanced(parentheses) ? "true" : "false") << endl;

    parentheses = "[(])";
    cout << "IsBalanced(" << parentheses << ")? " << (is_balanced(parentheses) ? "true" : "false") << endl;
    
    return 0;
}
