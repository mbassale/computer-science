//
// Created by Marco Bassaletti on 04-03-21.
//
#include <iostream>
#include <boost/asio.hpp>

void connect_sync() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver{ io_context };
    boost::asio::ip::tcp::socket socket{ io_context };
    try {
        auto endpoints = resolver.resolve("www.mbassale.cl", "http");
        const auto connected_endpoint = boost::asio::connect(socket, endpoints);
        std::cout << connected_endpoint << std::endl;
    } catch(boost::system::system_error& se) {
        std::cerr << "Error: " << se.what() << std::endl;
    }
}

void connect_async() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver{ io_context };
    boost::asio::ip::tcp::socket socket{ io_context };
    boost::asio::async_connect(socket, resolver.resolve("www.mbassale.cl", "http"),
                               [](boost::system::error_code ec, const auto& endpoint) {
        std::cout << endpoint << std::endl;
    });
    io_context.run();
}

int main() {
    connect_sync();
    connect_async();
}
