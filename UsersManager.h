#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersXMLfile.h"
#include "CommonMethods.h"

using namespace std;

class UsersManager {
    vector<User> users;
    UsersXMLFile usersXMLFile;
    int lastUserId;

    User inputNewUserData();
    int generateNewUserId();
    bool isLoginTaken(string login);

public:
    UsersManager(string usersFileName)
        : usersXMLFile(usersFileName) {
        users = usersXMLFile.loadUsersFromFile();
        lastUserId = usersXMLFile.getLastUserId();
    }
    void displayAllUsersData();
    int getLastUserId();
    void setLastUserId(int userId);
    void registerNewUser();

};


#endif // USERSMANAGER_H
