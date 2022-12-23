#ifndef CASHFLOWAPP_H
#define CASHFLOWAPP_H

#include <iostream>
#include "UsersManager.h"
#include "IncomesExpensesManager.h"

using namespace std;

class CashFlowApp {
    UsersManager usersManager;
    IncomesExpensesManager *incomesExpensesManager;
    const string USERS_FILE_NAME;

    void showLogonMenu();
    char chooseOptionFromLogonMenu();
    void showMainMenu();
    char chooseOptionFromMainMenu();
    void logoutUser();

public:
    CashFlowApp(string usersFileName = "users.xml"):
        usersManager(usersFileName) {
        incomesExpensesManager = NULL;
        showLogonMenu();
    };
    ~CashFlowApp() {
        delete incomesExpensesManager;
        incomesExpensesManager = NULL;
    }
    void userLogon();


};


#endif // CASHFLOWAPP_H
