#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersXMLfile.h"

using namespace std;

class UsersManager {
    vector<User> users;
    UsersXMLFile usersXMLFile;
    int lastUserId;

public:
    UsersManager(string usersFileName)
    : usersXMLFile(usersFileName) {
    users = usersXMLFile.loadUsersFromFile();
    }
    void displayAllUsersData();

};


#endif // USERSMANAGER_H