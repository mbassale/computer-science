//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../catch.hpp"
#include <iostream>
#include <memory>

using namespace std;

class Simple {
public:
    Simple() { cout << "Simple constructor called!" << endl; }

    ~Simple() { cout << "Simple destructor called!" << endl; }

    void go() { cout << "Executing go!" << endl; }
};

TEST_CASE("unique_ptr") {
    auto simple_ptr = make_unique<Simple>();
    simple_ptr->go();
    (*simple_ptr).go();
}

TEST_CASE("unique_ptr reset") {
    auto simple_ptr = make_unique<Simple>();
    simple_ptr->go();
    simple_ptr.reset();
    REQUIRE_FALSE(simple_ptr.get());
    simple_ptr = std::make_unique<Simple>();
    REQUIRE(simple_ptr.get());
}

TEST_CASE("shared_ptr") {
    auto simple_ptr = make_shared<Simple>();
    shared_ptr<Simple> simple_ptr2(simple_ptr);
}

class Foo {
public:
    explicit Foo(int value) : data{value} { cout << "Foo(" << data << ")" << endl; }

    ~Foo() { cout << "~Foo(" << data << ")" << endl; }

    int data;
};

TEST_CASE("shared_ptr aliasing") {
    auto foo = make_shared<Foo>(42);
    auto aliasing = shared_ptr<int>(foo, &foo->data);
    REQUIRE(*aliasing == 42);
}

TEST_CASE("weak_ptr") {
    auto use_resource = [](weak_ptr<Simple> &weak_simple) {
        auto resource = weak_simple.lock();
        if (resource) {
            cout << "Resource still alive." << endl;
        } else {
            cout << "Resource has been freed!" << endl;
        }
    };

    auto shared_simple = make_shared<Simple>();
    weak_ptr<Simple> weak_simple(shared_simple);
    use_resource(weak_simple);
    shared_simple.reset();
    use_resource(weak_simple);
}

TEST_CASE("move semantics") {
    auto create = []() {
        auto ptr = make_unique<Simple>();
        return ptr;
    };

    unique_ptr<Simple> simple_ptr = create();
    REQUIRE(simple_ptr.get());
    auto simple_ptr2 = create();
    REQUIRE(simple_ptr2.get());
}

class Foo2 : public enable_shared_from_this<Foo2> {
public:
    shared_ptr<Foo2> get_pointer() {
        return shared_from_this();
    }
};

TEST_CASE("enable_shared_from_this") {
    auto ptr1 = make_shared<Foo2>();
    auto ptr2 = ptr1->get_pointer();
    REQUIRE(ptr1.get() == ptr2.get());
}
