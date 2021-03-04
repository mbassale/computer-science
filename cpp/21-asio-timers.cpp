//
// Created by Marco Bassaletti on 03-03-21.
//
#include <iostream>
#include <boost/asio.hpp>
#include <chrono>

boost::asio::steady_timer make_timer(boost::asio::io_context& io_context) {
    return boost::asio::steady_timer{
        io_context,
        std::chrono::steady_clock::now() + std::chrono::seconds{ 3 }
    };
}

int main() {
    boost::asio::io_context io_context;

    auto timer1 = make_timer(io_context);
    std::cout << "entering steady_timer::wait" << std::endl;
    timer1.wait();
    std::cout << "exited steady_time::wait" << std::endl;

    auto timer2 = make_timer(io_context);
    std::cout << "entering steady_timer::async_wait" << std::endl;
    timer2.async_wait([] (const boost::system::error_code& error) {
        if (!error) std::cout << "<<callback function>>" << std::endl;
    });
    std::cout << "exited steady_time::async_wait" << std::endl;
    std::cout << "entering io_context::run" << std::endl;
    io_context.run();
    std::cout << "exited io_context::run" << std::endl;
}
