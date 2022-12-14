#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersXMLfile.h"

using namespace std;

class UsersManager {
    vector<User> users;
    UsersXMLFile usersXmlFile;
    int lastUserId;

public:
    UsersManager() {
    users = usersXmlFile.loadUsersFromFile();
    }
    void displayAllUsersData();

};


#endif // USERSMANAGER_H
