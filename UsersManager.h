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
    UsersXMLfile usersXMLfile;
    int lastUserId;
    int loggedUserId;
    User inputNewUserData();
    bool isLoginTaken(string login);
    void loadUsersFromXMLdocument(CMarkup *xmlDocument);
    User readSingleUserDataFromXML(CMarkup *xmlDocument);

public:
    UsersManager(string usersFileName)
        : usersXMLfile(usersFileName) {
        lastUserId = 0;
        loadUsersFromXMLdocument(usersXMLfile.getXMLdocument());
    }
    void displayAllUsersData();
    void registerNewUser();
    int getLoggedUserId();
    void userLogon();
    bool isUserLoggedIn();
    void logoutUser();
    void changePassword();

};


#endif // USERSMANAGER_H
