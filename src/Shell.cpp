#include "../include/Shell.h"

#include <iostream>

Shell::Shell(const std::string& username)
    : currentUser(username)
{
}

void Shell::printHelp() const
{
    std::cout << "\nAvailable Commands:\n";
    std::cout << "help      - Show this help message\n";
    std::cout << "whoami    - Show current user\n";
    std::cout << "history   - Show command history\n";
    std::cout << "clear     - Clear the screen\n";
    std::cout << "logout    - Logout and return to menu\n";
    std::cout << "exit      - Exit BilalOS\n\n";
}

bool Shell::start()
{
    std::string command;

    while (true)
    {
        std::cout << "BilalOS> ";
        std::getline(std::cin, command);

        if (command.empty())
        {
            continue;
        }

        history.push_back(command);

        if (command == "help")
        {
            printHelp();
        }
        else if (command == "whoami")
        {
            std::cout << currentUser << "\n";
        }
        else if (command == "history")
        {
            for (std::size_t i = 0; i < history.size(); ++i)
            {
                std::cout << i + 1 << ". "
                          << history[i] << '\n';
            }
        }
        else if (command == "clear")
        {
            for (int i = 0; i < 40; ++i)
            {
                std::cout << '\n';
            }
        }
        else if (command == "logout")
        {
            return false;
        }
        else if (command == "exit")
        {
            return true;
        }
        else
        {
            std::cout << "Unknown command. Type 'help'.\n";
        }
    }
}