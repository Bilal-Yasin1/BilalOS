#include "../include/Shell.h"

#include <iostream>

Shell::Shell(const std::string& username)
    : currentUser(username)
{
}

void Shell::printHelp() const
{
    std::cout << "\nAvailable Commands\n";
    std::cout << "------------------\n";
    std::cout << "help       Show all commands\n";
    std::cout << "whoami     Show current user\n";
    std::cout << "history    Show command history\n";
    std::cout << "clear      Clear screen\n";
    std::cout << "version    Show BilalOS version\n";
    std::cout << "echo       Print text\n";
    std::cout << "logout     Return to main menu\n";
    std::cout << "exit       Exit BilalOS\n\n";
}

bool Shell::executeCommand(const std::string& command)
{
    if (command == "help")
    {
        printHelp();
    }
    else if (command == "whoami")
    {
        std::cout << currentUser << '\n';
    }
    else if (command == "history")
    {
        for (std::size_t i = 0; i < history.size(); ++i)
        {
            std::cout << i + 1
                      << ". "
                      << history[i]
                      << '\n';
        }
    }
    else if (command == "clear")
    {
        for (int i = 0; i < 40; ++i)
        {
            std::cout << '\n';
        }
    }
    else if (command == "version")
    {
        std::cout << "BilalOS v0.2\n";
    }
    else if (command.rfind("echo ", 0) == 0)
    {
        std::cout << command.substr(5) << '\n';
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
        std::cout
            << "Unknown command. Type 'help'.\n";
    }

    return false;
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

        bool result = executeCommand(command);

        if (command == "logout")
        {
            return false;
        }

        if (command == "exit")
        {
            return true;
        }

        (void)result;
    }
}