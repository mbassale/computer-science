//
// Created by Marco Bassaletti on 04-03-21.
//
#include <iostream>
#include <boost/asio.hpp>

void resolve_method1() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver{ io_context };
    boost::system::error_code ec;
    for (auto&& result : resolver.resolve("www.mbassale.cl", "http", ec))
    std::cout << result.service_name() << " " << result.host_name() << " " << result.endpoint() << std::endl;
    if (ec) std::cout << "Error code: " << ec << std::endl;
};

void resolve_method2() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver{ io_context };
    resolver.async_resolve("www.mbassale.cl", "http", [](boost::system::error_code ec, const auto& results) {
        if (ec) {
            std::cerr << "Error: " << ec << std::endl;
            return;
        }
        for (auto&& result : results)
            std::cout << result.service_name() << " " << result.host_name() << " " << result.endpoint() << std::endl;
    });
    io_context.run();
}

int main() {
    resolve_method1();
    resolve_method2();
}
