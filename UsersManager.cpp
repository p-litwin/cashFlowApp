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

void UsersManager::registerNewUser() {
    User newUser = inputNewUserData();
    users.push_back(newUser);
    lastUserId = newUser.getUserId();
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
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
