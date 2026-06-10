#ifndef USER_H
#define USER_H

#include <string>

class User{

    private:    // User data
    std::string username;
    std::string password;

    public:  // Functions to set and get user data

    User();

    User(const std::string& username,const std::string& password);

    std::string getUsername() const;
    std::string getPassword() const;
};

#endif