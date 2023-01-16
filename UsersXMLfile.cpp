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

void UsersXMLfile::updatePasswordInXMLdocument(int loggedUserId, string newPassword) {
    if (findUserInXMLbyId(loggedUserId)) {
        xmlDocument.SetAttrib("password", newPassword);
        xmlDocument.Save("users.xml");
        cout << "Haslo zostalo pomyslnie zmienione" << endl;
        system("Pause");
    } else {
        cout << "Uzytkownik nie zostal znaleziony w pliku XML." << endl;
        system("Pause");
    }
}

bool UsersXMLfile::findUserInXMLbyId(int userId) {
    string idAsText = to_string(userId);
    xmlDocument.ResetPos();
    xmlDocument.FindElem("users");
    xmlDocument.IntoElem();
    while (xmlDocument.FindElem("user")) {
        if (xmlDocument.GetAttrib("id") == idAsText) {
            return true;
        }
    }
    return false;
}
