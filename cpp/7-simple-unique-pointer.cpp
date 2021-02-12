#include <cstdio>
#include <stdexcept>

template <typename T>
struct SimpleUniquePointer {
    
    SimpleUniquePointer() = default;
    
    SimpleUniquePointer(T* pointer) : pointer{pointer} {}

    ~SimpleUniquePointer() {
        if (pointer) delete pointer;
    }

    SimpleUniquePointer(const SimpleUniquePointer&) = delete;
    SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept : pointer{other.pointer} {
        other.pointer = nullptr;
    } 
    SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
        if (pointer) delete pointer;
        pointer  = other.pointer;
        other.pointer = nullptr;
        return *this;
    }

    T* get() { 
        return pointer; 
    }
private:
    T* pointer;
};

struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s is constructed.\n", name);
    }
    ~Tracer() {
        printf("%s is destructed.\n", name);
    }
private:
    const char* name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
    printf("(cons) consumer_ptr: %p\n", consumer_ptr.get());
}

int main() {
    auto ptr_a = SimpleUniquePointer(new Tracer{"ptr_a"});
    printf("(main) ptr_a: 0x%p\n", ptr_a.get());
    consumer(std::move(ptr_a));
    printf("(main) ptr_: 0x%p\n", ptr_a.get());
    return 0;
}
