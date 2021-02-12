#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    SimpleString(size_t max_size) : max_size{max_size}, length{} {
        if (max_size == 0) {
            throw std::runtime_error{"Max size must be at least 1."};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    /**
     * Copy constructor.
     */
    SimpleString(const SimpleString& other) : max_size{other.max_size}, buffer{ new char[other.max_size] }, length{other.length} {
        std::strncpy(buffer, other.buffer, max_size);
    }

    /**
     * Move constructor.
     */
    SimpleString(SimpleString&& other) noexcept : max_size{other.max_size}, buffer{other.buffer}, length{other.length} {
        other.length = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }

    ~SimpleString() {
        if (buffer) delete[] buffer;
    }

    /**
     * Copy assignment operator.
     */
    SimpleString& operator=(const SimpleString& other) {
        if (this == &other) return *this;
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer, other.buffer, max_size);
        return *this;
    }

    /**
     * Move assignment operator.
     */
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) return *this;
        if (buffer) delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
        return *this;
    }

    void print(const char* tag) const {
        printf("%s: %s\n", tag, buffer);
    }

    bool append_line(const char* x) {
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size) return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
private:
    size_t max_size;
    char* buffer;
    size_t length;
};

struct SimpleStringOwner {
    SimpleStringOwner(const char *x) : string{10} {
        if (!string.append_line(x)) {
            throw std::runtime_error("Not enought memory!");
        }
        string.print("Constructed");
    }

    SimpleStringOwner(SimpleString&& x) : string{ std::move(x) } {}

    ~SimpleStringOwner() {
        string.print("About to destroy");
    }
private:
    SimpleString string;
};

void foo(SimpleString x) {
    x.append_line("This change is lost.");
}

struct Highlander {
    Highlander() {}
    Highlander(const Highlander&) = delete;
    Highlander& operator=(const Highlander&) = delete;
};

void ref_type(int &x) {
    printf("lvalue reference %d\n", x);
}
void ref_type(int &&x) {
    printf("rvalue reference %d\n", x);
}

int main() {
    SimpleString str1{ 115 };
    str1.append_line("Starbuck, whaddya hear?");
    str1.append_line("Nothin' but the rain.");
    str1.print("A");
    str1.append_line("Grab your gun and bring the cat in.");
    str1.append_line("Aye-aye sir, coming home.");
    str1.print("B");
    if (!str1.append_line("Galactica!")) {
        printf("String was not big enough to append another message.\n");
    }

    SimpleStringOwner x{ "x" };
    printf("x is alive\n");

    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    SimpleString a_copy{ a };
    a.append_line("inconvenience.");
    a_copy.append_line("incontinence.");
    foo(a);
    a.print("a");
    a_copy.print("a_copy");
    a_copy = a;
    a_copy.print("a_copy");

    Highlander h1;
    // Deleted default copy constructor
    //Highlander h2{ h1 };

    // lvalues and rvalues
    auto num = 1;
    ref_type(num);
    ref_type(std::move(num));
    ref_type(2);
    ref_type(num + 2);

    SimpleString s1{ 50 };
    s1.append_line("We apologize for the");
    SimpleString s2{ 50 };
    s2.append_line("Last message");
    s1.print("s1");
    s2.print("s2");
    s2 = std::move(s1);
    s2.print("s2");

    return 0;
}