#include <iostream>
#include <memory>

template <typename T>
class Node
{
private:
    std::shared_ptr<Node> _left_ptr;
    std::shared_ptr<Node> _right_ptr;
    T _value;

public:
    Node() {}
    Node(T value) : _value(value) {}
    Node(const Node &node) : _left_ptr(node._left_ptr), _right_ptr(node._right_ptr), _value(node._value) {}
    ~Node() {}

    Node &left()
    {
        return *_left_ptr;
    }

    Node &left(T value)
    {
        _left_ptr = std::make_shared<Node>(value);
        return *this;
    }

    Node &right()
    {
        return *_right_ptr;
    }

    Node &right(T value)
    {
        _right_ptr = std::make_shared<Node>(value);
        return *this;
    }

    T &value()
    {
        return _value;
    }

    /**
     * Sum all the nodes in the binary tree.
     * Time: O(n)
     * Memory: O(log(n))
     * 
     * @param <T>
     * @param node
     * @return
     */
    T sum()
    {
        return sum(_left_ptr) + _value + sum(_right_ptr);
    }

private:
    T sum(const std::shared_ptr<Node> &node)
    {
        if (!node)
            return 0;
        return sum(node->_left_ptr) + node->_value + sum(node->_right_ptr);
    }
};

int main()
{
    Node root(3);
    root.left(2);
    root.left().left(1);
    root.right(4);
    root.right().right(5);
    std::cout << "Sum: " << root.sum() << std::endl;
    return EXIT_SUCCESS;
}