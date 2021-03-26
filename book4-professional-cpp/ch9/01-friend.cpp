//
// Created by Marco Bassaletti on 25-03-21.
//
#include "../catch.hpp"

namespace Chapter9 {

    class Foo {
        friend class FooFactory;

    public:
        Foo() = default;

        [[nodiscard]] int get_value() const { return value; }

    private:
        int value = 0;
    };

    class FooFactory {
    public:
        static Foo create(int value) {
            Foo foo{};
            foo.value = value;
            return foo;
        }
    };

    TEST_CASE("Chapter 9: Friend classes.", "[chapter 9]") {
        auto foo = FooFactory::create(10);
        REQUIRE(foo.get_value() == 10);
    }

}
