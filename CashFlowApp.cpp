#include "CashFlowApp.h"

void CashFlowApp::showLogonMenu() {
    char selection;

    while (true) {
        if (!usersManager.isUserLoggedIn()) {
            selection = chooseOptionFromLogonMenu();

            switch (selection) {
            case '1':
                usersManager.registerNewUser();
                break;
            case '2':
                userLogon();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

}

char CashFlowApp::chooseOptionFromLogonMenu() {
    char selection;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    selection = CommonMethods::getSingleCharacter();

    return selection;
}

void CashFlowApp::userLogon() {
    usersManager.userLogon();
    if (usersManager.isUserLoggedIn()) {
        incomesExpensesManager = new IncomesExpensesManager(usersManager.getLoggedUserId());
        //load incomes and expenses to the memory
        showMainMenu();
    }

}

void CashFlowApp::showMainMenu() {
    char selection;
    while (true) {
        selection = chooseOptionFromMainMenu();
        switch (selection) {
        case '1':
            incomesExpensesManager -> addNewIncome();
            break;
        case '2':
            incomesExpensesManager -> addNewExpense();
            break;
        case '3':
            incomesExpensesManager -> displayCurrentMonthBalance();
            break;
        case '4':
            incomesExpensesManager -> displayPreviousMonthBalance();
            break;
        case '5':

            break;
        case '6':
            usersManager.changePassword();
            break;
        case '7':
            logoutUser();
            break;
        }
    }

}

char CashFlowApp::chooseOptionFromMainMenu() {
    char selection;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    selection = CommonMethods::getSingleCharacter();

    return selection;
}

void CashFlowApp::logoutUser() {
    usersManager.logoutUser();
    delete incomesExpensesManager;
    incomesExpensesManager = NULL;
    showLogonMenu();
    }
