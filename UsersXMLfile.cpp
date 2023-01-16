#include "UsersXMLfile.h"

void UsersXMLfile::addNewUserToXMLdocument(User newUser) {
    xmlDocument.ResetPos();
    if (xmlDocument.FindElem("users") == false) {
        xmlDocument.SetDoc("<?xml version='1.0'?>\n");
        xmlDocument.AddElem("users");
    }
    xmlDocument.IntoElem();
    xmlDocument.AddElem("user");
    xmlDocument.AddAttrib("id", newUser.getUserId());
    xmlDocument.AddAttrib("name", newUser.getUserName());
    xmlDocument.AddAttrib("surname", newUser.getUserSurname());
    xmlDocument.AddAttrib("login", newUser.getLogin());
    xmlDocument.AddAttrib("password", newUser.getPassword());
}

//vector<User> UsersXMLFile::loadUsersFromFile() {
//    vector<User> users;
//    bool isxmlDocumentOpened;
//    User singleUser;
//    CMarkup xmlDocument;
//    CMarkup* xmlDocumentPtr = &xmlDocument;
//    isxmlDocumentOpened = xmlDocument.Load(USERS_FILE_NAME);
//    if (isxmlDocumentOpened ==  true) {
//        xmlDocument.FindElem("users");
//        xmlDocument.IntoElem();
//
//        while (xmlDocument.FindElem("user") ) {
//            singleUser = readSingleUserDataFromFile(xmlDocumentPtr);
//            lastUserId = singleUser.getUserId();
//            users.push_back(singleUser);
//        }
//    }
//
//    return users;
//}
//
//User UsersXMLFile::readSingleUserDataFromFile(CMarkup *file) {
//    User user;
//    user.setUserId( stoi(file -> GetAttrib("id")) );
//    user.setUserName(file -> GetAttrib("name"));
//    user.setUserSurname(file -> GetAttrib("surname"));
//    user.setLogin(file -> GetAttrib("login"));
//    user.setPassword(file -> GetAttrib("password"));
//    return user;
//}
//
//int UsersXMLFile::getLastUserId() {
//    return lastUserId;
//}
//
//void UsersXMLFile::saveUsersToXMLfile(User newUser) {
//    CMarkup xmlDocument;
//    xmlDocument.Load("users.xml");
//    if (xmlDocument.FindElem("users") == false) {
//        xmlDocument.SetDoc("<?xml version='1.0'?>\n");
//        xmlDocument.AddElem("users");
//    }
//    xmlDocument.IntoElem();
//    xmlDocument.AddElem("user");
//    xmlDocument.AddAttrib("id", newUser.getUserId());
//    xmlDocument.AddAttrib("name", newUser.getUserName());
//    xmlDocument.AddAttrib("surname", newUser.getUserSurname());
//    xmlDocument.AddAttrib("login", newUser.getLogin());
//    xmlDocument.AddAttrib("password", newUser.getPassword());
//    xmlDocument.Save("users.xml");
//}
//
//void UsersXMLFile::updatePasswordInXMLfile(int loggedUserId, string newPassword) {
//    CMarkup xml;
//    xml.Load("users.xml");
//    CMarkup *xmlDoc = & xml;
//    if (findUserElementById(*xmlDoc, loggedUserId)) {
//        xml.SetAttrib("password", newPassword);
//        xml.Save("users.xml");
//        cout << "Haslo zostalo pomyslnie zmienione" << endl;
//        system("Pause");
//    } else {
//        cout << "Uzytkownik nie zostal znaleziony w pliku XML." << endl;
//        system("Pause");
//    }
//}
//
//bool UsersXMLFile::findUserElementById(CMarkup &xml, int userId) {
//    string idAsText = to_string(userId);
//    xml.ResetPos();
//    xml.FindElem("users");
//    xml.IntoElem();
//    while (xml.FindElem("user")) {
//        if (xml.GetAttrib("id") == idAsText) {
//            return true;
//        }
//    }
//    return false;
//}
