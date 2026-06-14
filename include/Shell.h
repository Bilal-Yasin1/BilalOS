#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

class Shell
{
private:
    std::string currentUser;
    std::vector<std::string> history;

    bool executeCommand(const std::string& command);
    void printHelp() const;

public:
    explicit Shell(const std::string& username);

    bool start();
};

#endif