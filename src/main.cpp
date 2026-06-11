#include <iostream>

#include "D:\BilalOS\include\UserManager.h"

int main()
{
    UserManager manager;

    manager.loadUsers();

    int choice;

    while (true)
    {
        std::cout
            << "1. Register\n"
            << "2. Login\n"
            << "3. Exit\n";

        std::cin >> choice;

        if (choice == 1)
        {
            std::string username;
            std::string password;

            std::cout << "Username: ";
            std::cin >> username;

            std::cout << "Password: ";
            std::cin >> password;

            if (manager.registerUser(
                    username,
                    password))
            {
                std::cout
                    << "Registration successful\n";
            }
            else
            {
                std::cout
                    << "Username already exists\n";
            }
        }
        else if (choice == 2)
        {
            std::string username;
            std::string password;

            std::cout << "Username: ";
            std::cin >> username;

            std::cout << "Password: ";
            std::cin >> password;

            if (manager.loginUser(
                    username,
                    password))
            {
                std::cout
                    << "Login successful\n";
            }
            else
            {
                std::cout
                    << "Invalid credentials\n";
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}