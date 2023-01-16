#include "UsersManager.h"


void UsersManager::displayAllUsersData() {
    for (size_t i = 0; i < users.size(); i++ ) {

        cout << users[i].getUserId() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

int UsersManager::getLastUserId() {
    return lastUserId;
}

void UsersManager::setLastUserId(int userId) {
    this -> lastUserId = userId;
}

void UsersManager::loadUsersFromXMLdocument(CMarkup *xmlDocument) {
    User singleUser;
    xmlDocument -> FindElem("users");
    xmlDocument -> IntoElem();
    while (xmlDocument -> FindElem("user")) {
        lastUserId = stoi(xmlDocument -> GetAttrib("id"));
        singleUser = readSingleUserDataFromXML(xmlDocument);
        users.push_back(singleUser);
    }
}

User UsersManager::readSingleUserDataFromXML(CMarkup *xmlDocument) {
    User user;
    user.setUserId( stoi(xmlDocument -> GetAttrib("id")) );
    user.setUserName(xmlDocument -> GetAttrib("name"));
    user.setUserSurname(xmlDocument -> GetAttrib("surname"));
    user.setLogin(xmlDocument -> GetAttrib("login"));
    user.setPassword(xmlDocument -> GetAttrib("password"));
    return user;
}

void UsersManager::registerNewUser() {
    User newUser = inputNewUserData();
    users.push_back(newUser);
    lastUserId = newUser.getUserId();
    //usersXMLFile.saveUsersToXMLfile(newUser);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UsersManager::inputNewUserData() {

    User newUser;
    newUser.setUserId(generateNewUserId());
    cout << "Podaj Imie: ";
    string name = CommonMethods::getLineOfText();
    newUser.setUserName(name);
    cout << "Podaj nazwisko: ";
    string surname = CommonMethods::getLineOfText();
    newUser.setUserSurname(surname);
    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        newUser.setLogin(login);
    } while (isLoginTaken(newUser.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    password = CommonMethods::getLineOfText();
    newUser.setPassword(password);
    return newUser;
}

int UsersManager::generateNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return lastUserId + 1;
}

bool UsersManager::isLoginTaken(string login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UsersManager::userLogon() {
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = CommonMethods::getLineOfText();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int trialCount = 3; trialCount > 0; trialCount--) {
                cout << "Podaj haslo. Pozostalo prob: " << trialCount << ": ";
                password = CommonMethods::getLineOfText();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            loggedUserId = 0;
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedUserId = 0;
    return;
}

bool UsersManager::isUserLoggedIn() {
    if (loggedUserId != 0)
        return true;
    else
        return false;
}

void UsersManager::logoutUser() {
    loggedUserId = 0;
}

void UsersManager::changePassword() {
    cout << "Podaj nowe haslo: ";
    string newPassword = CommonMethods::getLineOfText();
    for (size_t i = 0; i < users.size(); i++ ) {
        if (users[i].getUserId() == loggedUserId) {
            users[i].setPassword(newPassword);
//            usersXMLFile.updatePasswordInXMLfile(loggedUserId, newPassword);
            return;
        }
    }
    return;
}

int UsersManager::getLoggedUserId() {
    return loggedUserId;
}
