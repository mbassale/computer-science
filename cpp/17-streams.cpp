#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>


TEST_CASE("cout (as ostringstream) global output stream") {
    using namespace std;
    bitset<8> s{ "01110011" };
    string str("Crying zeros and I'm hearing");
    size_t num{ 111 };
    ostringstream oss;
    oss << s << '\n' << str << "\n" <<  num << "\n";
    REQUIRE(oss.str() == "01110011\nCrying zeros and I'm hearing\n111\n");
}

TEST_CASE("cin (as istringstream) global input stream") {
    using namespace std;
    double x, y;
    istringstream is;
    is.str("10 5 *");
    ostringstream os;
    os << "X: ";
    is >> x;
    os << "Y: ";
    is >> y;

    REQUIRE(os.str() == "X: Y: ");
    REQUIRE(x == 10);
    REQUIRE(y == 5);

    string op;
    os << "Operation: ";
    is >> op;
    REQUIRE(os.str() == "X: Y: Operation: ");
    REQUIRE(op == "*");

    if (op == "+") {
        os << x + y;
    } else if (op == "-") {
        os << x - y;
    } else if (op == "*") {
        os << x * y;
    } else if (op == "/") {
        os << x / y;
    } else {
        os << "Unknown operation" << op;
    }
    os << endl;

    REQUIRE(os.str() == "X: Y: Operation: 50\n");
}

TEST_CASE("cin (as istringstream) word count") {
    using namespace std;
    istringstream is;
    is.str("one two three four five six seven eight");
    std::string word;
    size_t count{};
    while (is >> word) {
        count++;
    }
    ostringstream os;
    os << "Discovered " << count << " words.\n";
    REQUIRE(os.str() == "Discovered 8 words.\n");
}

TEST_CASE("stream exceptions") {
    using namespace std;
    ostringstream os;
    istringstream is;
    is.str("one two three four five six seven eight");
    is.exceptions(istream::badbit);
    string word;
    size_t count{};
    try {
        while(is >> word) count++;
        os << "Discovered " << count << " words.\n";
        REQUIRE(os.str() == "Discovered 8 words.\n");
    } catch (const std::exception& e) {
        os << "Error occurred reading from stdin: " << e.what();
        REQUIRE(os.str() == string("Error occurred reading from stdin: ") + e.what());
    }
}

TEST_CASE("stream manipulators") {
    using namespace std;
    ostringstream os;
    os << "Gotham needs its " << boolalpha << true << " hero.";
    os << "\nMark it " << noboolalpha << false << "!";
    os << "\nThere are " << 69 << "," << oct << 105 << " leaves in here.";
    os << "\nYabba " << hex << 3669732608 << "!";
    os << "\nAvogadro's number: " << scientific << 6.0221415e-23;
    os << "\nthe Hogwarts platform: " << fixed << setprecision(2) << 9.750123;
    os << "\nAlways eliminate " << 3735929054;
    REQUIRE(os.str() == "Gotham needs its true hero.\n"
                        "Mark it 0!\n"
                        "There are 69,151 leaves in here.\n"
                        "Yabba dabbad00!\n"
                        "Avogadro's number: 6.022142e-23\n"
                        "the Hogwarts platform: 9.75\n"
                        "Always eliminate deadc0de");
}
