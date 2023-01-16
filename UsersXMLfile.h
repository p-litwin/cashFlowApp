#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include "User.h"
#include "Markup.h"
#include <vector>
#include "XMLfile.h"

using namespace std;

class UsersXMLfile:public XMLfile {
    bool findUserInXMLbyId(int userId);
public:
    UsersXMLfile(string fileName)
        :XMLfile(fileName) {
    };
    void addNewUserToXMLdocument(User newUser);
    void updatePasswordInXMLdocument(int loggedUserId, string newPassword);
};

#endif // USERSXMLFILE_H
