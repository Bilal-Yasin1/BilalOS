#include "D:\BilalOS\include\UserManager.h"

#include <fstream>
#include <sstream>

void UserManager::loadUsers(){

    users.clear();
    std::ifstream file("data/users.txt");

    if (!file){
        return;
    }

    std::string line;

    while (std::getline(file,line))
    {
        std::stringstream ss(line);

        std::string username,password;

        std::getline(ss,username,',');
        std::getline(ss,password);

        users.push_back(User(username,password));

    }
}

void UserManager::saveUsers(){

    std::ofstream file("data/users.txt");

    for (const User& user : users){

        file <<user.getUsername()
             <<","
             <<user.getPassword()
             <<"\n";
    }
}

bool UserManager::usernameExists(const std::string& username) const{

    for (const User& user : users){

        if (user.getUsername()==username){
            return true;
        }
    }

    return false;
}

bool UserManager::registerUser(const std::string& username, const std::string& password){

    if(usernameExists(username)){
        return false;
    }

    users.push_back(User(username,password));

    saveUsers();
    return true;
}

bool UserManager::loginUser(const std::string&username, const std::string& password) const {

    for(const User& user : users){

        if(user.getUsername()==username && user.getPassword()==password){

            return true;
        }
    }
    return false;
}