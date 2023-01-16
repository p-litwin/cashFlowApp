#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include "User.h"
#include "Markup.h"
#include <vector>
#include "XMLfile.h"

using namespace std;

class UsersXMLfile:public XMLfile {

public:
    UsersXMLfile(string fileName)
    :XMLfile(fileName) {
    };
    void addNewUserToXMLdocument(User newUser);
};

//    User readSingleUserDataFromFile(CMarkup *file);
//    bool findUserElementById(CMarkup &xml, int userId);
//
//public:
//    UsersXMLFile(string fileName)
//        : USERS_FILE_NAME(fileName) {
//        lastUserId = 0;
//    };
//
//    vector<User> loadUsersFromFile();
//    int getLastUserId();
//    void saveUsersToXMLfile(User newUser);
//    void updatePasswordInXMLfile(int loggedUserId, string newPassword);
//};



#endif // USERSXMLFILE_H
