#include <iostream>
#include "D:\BilalOS\include\User.h"

int main()
{
    User user("bilal", "password123");
    std::cout<<user.getUsername()<<std::endl;
    return 0;
}