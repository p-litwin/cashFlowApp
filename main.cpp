#include <iostream>
#include "CashFlowApp.h"

using namespace std;

int main()
{
    UsersManager usersManager("users.xml");
    usersManager.displayAllUsersData();
    usersManager.registerNewUser();
    usersManager.registerNewUser();
    usersManager.displayAllUsersData();
    //cout << << endl;
    return 0;
}
