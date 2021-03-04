//
// Created by Marco Bassaletti on 04-03-21.
//
#include <cstdlib>
#include <iostream>
#include <string>

struct Tracer {
    Tracer(std::string name_in) : name{ std::move(name_in) } {
        std::cout << name << " constructed." << std::endl;
    }
    ~Tracer() {
        std::cout << name << " destroyed." << std::endl;
    }
private:
    const std::string name;
};

Tracer static_tracer{ "Static Tracer" };

void run() {
    std::cout << "Entering run()" << std::endl;
    std::atexit([]{ std::cout << "***std::atexit callback executing***" << std::endl; });
    //std::exit(0); // No stack unwinding on main.
    //std::abort(); // Nuke program.
    std::cout << "Exiting run()" << std::endl;
}

int main() {
    std::cout << "Entering main()" << std::endl;
    Tracer local_tracer{ "Local Tracer"};
    thread_local Tracer thread_local_tracer{ "Thread Local Tracer" };
    const auto* dynamic_tracer = new Tracer{ "Dynamic Tracer" };
    run();
    delete dynamic_tracer;
    std::cout << "Exiting main()" << std::endl;
    return 0;
}
