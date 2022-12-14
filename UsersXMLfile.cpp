#include "UsersXMLfile.h"

vector<User> UsersXMLFile::loadUsersFromFile() {
    vector<User> users;
    User singleUser;
    CMarkup xmlFile;
    CMarkup* xmlFilePtr = &xmlFile;
    xmlFile.Load("users.xml");

    xmlFile.FindElem("users");
    xmlFile.IntoElem();

    while (xmlFile.FindElem("user") ) {
        singleUser = readSingleUserDataFromFile(xmlFilePtr);
        users.push_back(singleUser);
    }

    return users;
}

User UsersXMLFile::readSingleUserDataFromFile(CMarkup *file) {
    User user;
    user.setUserId( stoi(file -> GetAttrib("id")) );
    user.setUserName(file -> GetAttrib("name"));
    user.setUserSurname(file -> GetAttrib("surname"));
    user.setLogin(file -> GetAttrib("login"));
    user.setPassword(file -> GetAttrib("password"));
    return user;
}
