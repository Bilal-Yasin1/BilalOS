#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "User.h"

class UserManager {

    private:
    std::vector<User> users;

    public:

    void loadUsers();
    void saveUsers();

    bool usernameExists(const std::string& username) const;

    bool registerUser(const std::string& username, const std::string& password);
    
    bool loginUser(const std::string& username,const std::string& password) const;

};

#endif