#include "server.h"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void start_server() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Server started on port 12345...\n";

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::cout << "Client connected!\n";

            char buffer[1024];
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buffer), error);

            if (!error) {
                std::cout << "Received: " << std::string(buffer, len) << std::endl;
                std::string response = "Message received!";
                boost::asio::write(socket, boost::asio::buffer(response), error);
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << "\n";
    }
}
