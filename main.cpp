#include <iostream>
#include "main.h"

int main() {
    std::cout << "Choose mode:\n1. Server\n2. Client\nEnter choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        start_server();
    } else if (choice == 2) {
        start_client();
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
