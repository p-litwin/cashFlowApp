#include "UsersManager.h"


void UsersManager::displayAllUsersData() {
    if (users.size() > 0) {
        cout << users[2].getUserId() << endl;
        cout << users[2].getUserName() << endl;
        cout << users[2].getUserSurname() << endl;
        cout << users[2].getLogin() << endl;
        cout << users[2].getPassword() << endl;
    }
}
