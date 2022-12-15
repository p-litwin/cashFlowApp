#include <iostream>
#include "CashFlowApp.h"

using namespace std;

int main()
{
    UsersManager usersManager("users.xml");
    usersManager.displayAllUsersData();
    //cout << << endl;
    return 0;
}
