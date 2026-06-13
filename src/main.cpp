#include <iostream>
#include <limits>
#include <string>

#include "../include/UserManager.h"
#include "../include/Shell.h"

int main()
{
    UserManager manager;
    manager.loadUsers();

    while (true)
    {
        std::cout << "\n=========================\n";
        std::cout << "      BilalOS v0.1\n";
        std::cout << "=========================\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        // Clear the newline left by std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1)
        {
            std::string username;
            std::string password;

            std::cout << "Enter username: ";
            std::getline(std::cin, username);

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (manager.registerUser(username, password))
            {
                std::cout << "User registered successfully.\n";
            }
            else
            {
                std::cout << "Username already exists.\n";
            }
        }
        else if (choice == 2)
        {
            std::string username;
            std::string password;

            std::cout << "Enter username: ";
            std::getline(std::cin, username);

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (manager.loginUser(username, password))
            {
                std::cout << "\nLogin successful. Welcome, "
                          << username << "!\n\n";

                Shell shell(username);

                bool shouldExit = shell.start();

                if (shouldExit)
                {
                    break;
                }
            }
            else
            {
                std::cout << "Invalid username or password.\n";
            }
        }
        else if (choice == 3)
        {
            std::cout << "Exiting BilalOS...\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}