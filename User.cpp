#include "User.h"


void User::setUserId(int newId) {
    this -> userId = newId;
}
void User::setUserName(string userName) {
    this -> userName = userName;
}
void User::setUserSurname(string userSurname) {
    this -> userSurname = userSurname;
}
void User::setLogin(string login) {
    this -> login = login;
}
void User::setPassword(string password) {
    this -> password = password;
}

int User::getUserId() {
    return userId;
}
string User::getUserName() {
    return userName;
}
string User::getUserSurname() {
    return userSurname;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}
