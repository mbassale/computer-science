#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <bitset>
#include <iomanip>

using namespace std;

TEST_CASE("cout (as ostringstream) global output stream") {
    bitset<8> s{ "01110011" };
    string str("Crying zeros and I'm hearing");
    size_t num{ 111 };
    ostringstream oss;
    oss << s << '\n' << str << "\n" <<  num << "\n";
    REQUIRE(oss.str() == "01110011\nCrying zeros and I'm hearing\n111\n");
}

TEST_CASE("cin (as istringstream) global input stream") {
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

template <typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> v) {
    s << "Size: " << v.size() << "\nCapacity: " << v.capacity() << "\nElements:\n";
    for (const auto& element : v) {
        s << "\t" << element << "\n";
    }
    return s;
}

TEST_CASE("user-defined types on ostream") {
    const vector<string> characters {
        "Bobby Shaftoe",
        "Lawrence Waterhouse",
        "Gunter Bischoff",
        "Earl Comstock"
    };
    ostringstream os;
    os << characters;
    ostringstream os2;
    os2 << "Size: 4\nCapacity: " << characters.capacity() << "\nElements:\n\tBobby Shaftoe\n\tLawrence Waterhouse\n\tGunter Bischoff\n\tEarl Comstock\n";
    REQUIRE(os.str() == os2.str());
}

template <typename T>
std::istream& operator>>(std::istream& s, std::deque<T>& t) {
    T element;
    while (s >> element) {
        t.emplace_back(std::move(element));
    }
    return s;
}

TEST_CASE("user-defined types on istream") {
    deque<int> numbers;
    istringstream is;
    is.str("1 2 3 4 5");
    is >> numbers;
    int sum{};
    ostringstream os;
    os << "Cumulative sum:\n";
    for (const auto& element : numbers) {
        sum += element;
        os << sum << "\n";
    }
    REQUIRE(os.str() == "Cumulative sum:\n1\n3\n6\n10\n15\n");
}

TEST_CASE("ostringstream produces strings with str") {
    ostringstream ss;
    ss << "By Grabthar's hammer, ";
    ss << "by the suns of Worvan. ";
    ss << "You shall be avenged.";
    const auto lazarus = ss.str();

    ss.str("I am Groot.");
    const auto groot = ss.str();

    REQUIRE(lazarus == "By Grabthar's hammer, by the suns of Worvan. You shall be avenged.");
    REQUIRE(groot == "I am Groot.");
}

TEST_CASE("istringstream supports construction from a string") {
    string numbers("1 2.23606 2");
    istringstream ss{ numbers };
    int a;
    float b, c, d;
    ss >> a;
    ss >> b;
    ss >> c;
    REQUIRE(a == 1);
    REQUIRE(b == Approx(2.23606));
    REQUIRE(c == Approx(2));
    REQUIRE_FALSE(ss >> d);
}

TEST_CASE("stringstream supports all strings stream operations") {
    stringstream ss;
    ss << "Zed's DEAD";

    string who;
    ss >> who;
    int what;
    ss >> hex >> what;

    REQUIRE(who == "Zed's");
    REQUIRE(what == 0xdead);
}

TEST_CASE("read & write to file") {
    {
        ofstream file{"numbers.txt", ios::out | ios::app};
        REQUIRE(file.is_open());
        vector<int> numbers{
                -54,
                203,
                9000,
                0,
                99,
                -789,
                400
        };
        for (const auto &number : numbers) {
            file << number << endl;
        }
        file.close();
        REQUIRE_FALSE(file.is_open());
    }
    ifstream file{ "numbers.txt" };
    REQUIRE(file.is_open());
    auto maximum = numeric_limits<int>::min();
    int value;
    while (file >> value) maximum = std::max(maximum, value);
    REQUIRE(maximum == 9000);
    file.close();
    REQUIRE_FALSE(file.is_open());
}

ifstream open(const char* path, ios_base::openmode mode = ios::ios_base::in) {
    ifstream file{ path, mode };
    if (!file.is_open()) {
        string err{ "Uname to open file " };
        err.append(path);
        throw runtime_error{ err };
    }
    file.exceptions(ifstream::badbit);
    return file;
}
