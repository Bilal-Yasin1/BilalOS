#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

class Shell
{
private:
    std::string currentUser;
    std::vector<std::string> history;

public:
    explicit Shell(const std::string& username);

    // Starts the shell loop
    bool start();

private:
    void printHelp() const;
};

#endif