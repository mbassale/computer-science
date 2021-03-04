//
// Created by Marco Bassaletti on 04-03-21.
//
#include <csignal>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>


std::atomic_bool interrupted{};

extern "C" void handler(int signal) {
    std::cout << "Handler invoked with signal " << signal << "." << std::endl;
    std::exit(0);
}

int main() {
    using namespace std::chrono_literals;
    std::signal(SIGINT, handler);
    while (!interrupted) {
        std::cout << "Waiting..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
    std::cout << "Interrupted!" << std::endl;
}
