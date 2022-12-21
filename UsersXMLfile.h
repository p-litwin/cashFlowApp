#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include "User.h"
#include "Markup.h"
#include <vector>

using namespace std;

class UsersXMLFile {
    const string USERS_FILE_NAME;
    int lastUserId;

    User readSingleUserDataFromFile(CMarkup *file);

public:
    UsersXMLFile(string fileName)
        : USERS_FILE_NAME(fileName) {
        lastUserId = 0;
    };

    vector<User> loadUsersFromFile();
    int getLastUserId();
    void saveUsersToXMLfile(User newUser);
};



#endif // USERSXMLFILE_H
