#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string userName;
    string userSurname;
    string login;
    string password;
public:
    void setUserId(int newId);
    void setUserName(string userName);
    void setUserSurname(string userSurname);
    void setLogin(string login);
    void setPassword(string password);
    int getUserId();
    string getUserName();
    string getUserSurname();
    string getLogin();
    string getPassword();
};


#endif // USER_H
