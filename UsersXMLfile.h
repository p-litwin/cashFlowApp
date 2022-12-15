#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include "User.h"
#include "Markup.h"
#include <vector>

using namespace std;

class UsersXMLFile {
    const string USERS_FILE_NAME;
    User readSingleUserDataFromFile(CMarkup *file);
public:
    UsersXMLFile(string fileName)
    : USERS_FILE_NAME(fileName) {};

    vector<User> loadUsersFromFile();
};



#endif // USERSXMLFILE_H
