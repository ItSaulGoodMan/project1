#include "client.h"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void start_client() {
    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve("127.0.0.1", "12345"));

        std::cout << "Connected to server!\n";

        while (true) {
            std::string message;
            std::cout << "Enter message: ";
            std::getline(std::cin, message);

            if (message == "exit") break;

            boost::asio::write(socket, boost::asio::buffer(message));

            char reply[1024];
            size_t reply_length = socket.read_some(boost::asio::buffer(reply));

            std::cout << "Server reply: " << std::string(reply, reply_length) << "\n";
        }
    } catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << "\n";
    }
}
