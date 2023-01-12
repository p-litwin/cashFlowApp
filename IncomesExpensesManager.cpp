#include "IncomesExpensesManager.h"

void IncomesExpensesManager::addNewExpense() {
    if (LOGGED_USER_ID != 0) {
        Expense newExpense;
        char selection;
        string item;
        float amount;
        cout << "Czy chcesz dodac wydatek z dzisiejsza data? T/N: ";
        selection = CommonMethods::getSingleCharacter();
        do {
            if (selection == 'T' || selection == 't') {
                newExpense.setDate(date.getCurrentDate());
            } else if (selection == 'N' || selection == 'n') {
                newExpense.setDate(date.getDateFromUser());
            } else {
                cout << "Wybierz T lub N z klawiatury.";
            }
        } while (selection != 'T' && selection != 't' && selection != 'N' && selection != 'n');
        item = CommonMethods::getMandatoryLineOfText("Podaj kategorie");
        amount = CommonMethods::getMandatoryFloatValue();
        newExpense.setUserId(LOGGED_USER_ID);
        newExpense.setItem(item);
        newExpense.setAmount(amount);
        newExpense.setId(++lastExpenseId);
        expenses.push_back(newExpense);
        expensesXMLfile -> addNewExpenseToXMLdocument(newExpense);
        expensesXMLfile -> saveXMLdocumentToFile();
        cout << "Nowy wydatek zostal dodany." << endl;
        system("pause");
    }
}

void IncomesExpensesManager::addNewIncome() {
    if (LOGGED_USER_ID != 0) {
        Income newIncome;
        char selection;
        string item;
        float amount;
        cout << "Czy chcesz dodac przychod z dzisiejsza data? T/N: ";
        selection = CommonMethods::getSingleCharacter();
        do {
            if (selection == 'T' || selection == 't') {
                newIncome.setDate(date.getCurrentDate());
            } else if (selection == 'N' || selection == 'n') {
                newIncome.setDate(date.getDateFromUser());
            } else {
                cout << "Wybierz T lub N z klawiatury.";
            }
        } while (selection != 'T' && selection != 't' && selection != 'N' && selection != 'n');
        item = CommonMethods::getMandatoryLineOfText("Podaj kategorie");
        amount = CommonMethods::getMandatoryFloatValue();
        newIncome.setUserId(LOGGED_USER_ID);
        newIncome.setItem(item);
        newIncome.setAmount(amount);
        newIncome.setId(++lastIncomeId);
        incomes.push_back(newIncome);
        incomesXMLfile -> addNewIncomeToXMLdocument(newIncome);
        incomesXMLfile -> saveXMLdocumentToFile();
        cout << "Nowy przychod zostal dodany." << endl;
        system("pause");
    }
}

void IncomesExpensesManager::displayExpense(int index) {
    cout << expenses[index].getId() << endl;
    cout << expenses[index].getDate() << endl;
    cout << expenses[index].getItem() << endl;
    cout << expenses[index].getAmount() << endl;
}

void IncomesExpensesManager::displayIncome(int index) {
    cout << incomes[index].getId() << endl;
    cout << incomes[index].getDate() << endl;
    cout << incomes[index].getItem() << endl;
    cout << incomes[index].getAmount() << endl;
}

void IncomesExpensesManager::loadIncomesForLoggedUser(CMarkup *xmlDocument) {
    Income singleIncome;
    xmlDocument -> FindElem("incomes");
    xmlDocument -> IntoElem();
    while (xmlDocument -> FindElem("income")) {
        if (stoi(xmlDocument -> GetAttrib("userId")) == LOGGED_USER_ID) {
            lastIncomeId = stoi(xmlDocument -> GetAttrib("incomeId"));
            singleIncome = readSingleIncomeFromXML(xmlDocument);
            incomes.push_back(singleIncome);
        }
    }
}

Income IncomesExpensesManager::readSingleIncomeFromXML(CMarkup *xmlDocument) {
    Income income;
    income.setId(stoi(xmlDocument -> GetAttrib("incomeId")));
    income.setDate(xmlDocument -> GetAttrib("date"));
    xmlDocument ->FindChildElem("item");
    xmlDocument -> IntoElem();
    income.setItem(xmlDocument -> GetData());
    xmlDocument -> OutOfElem();
    xmlDocument -> FindChildElem("amount");
    xmlDocument ->  IntoElem();
    income.setAmount(stof(xmlDocument -> GetData()));
    xmlDocument ->  OutOfElem();
    return income;
}

void IncomesExpensesManager::loadExpensesForLoggedUser(CMarkup *xmlDocument) {
    Expense singleExpense;
    xmlDocument -> FindElem("expenses");
    xmlDocument -> IntoElem();
    while (xmlDocument -> FindElem("expense")) {
        if (stoi(xmlDocument -> GetAttrib("userId")) == LOGGED_USER_ID) {
            lastExpenseId = stoi(xmlDocument -> GetAttrib("expenseId"));
            singleExpense = readSingleExpenseFromXML(xmlDocument);
            expenses.push_back(singleExpense);
        }
    }
}

Expense IncomesExpensesManager::readSingleExpenseFromXML(CMarkup *xmlDocument) {
    Expense expense;
    expense.setId(stoi(xmlDocument -> GetAttrib("expenseId")));
    expense.setDate(xmlDocument -> GetAttrib("date"));
    xmlDocument ->FindChildElem("item");
    xmlDocument -> IntoElem();
    expense.setItem(xmlDocument -> GetData());
    xmlDocument -> OutOfElem();
    xmlDocument -> FindChildElem("amount");
    xmlDocument ->  IntoElem();
    expense.setAmount(stof(xmlDocument -> GetData()));
    xmlDocument ->  OutOfElem();
    return expense;

}

void IncomesExpensesManager::displayCurrentMonthBalance() {
    system("cls");
    balance = new Balance(date.getcurrentMonthStartDate(), date.getCurrentMonthEndDate());
    balance -> loadIncomesForSelectedPeriod(getIncomesOfUser());
    balance -> sortIncomesByDate();
    cout << "Bilans za okres " << date.getcurrentMonthStartDate() << " - " << date.getCurrentMonthEndDate() << endl;
    balance -> displayIncomes();
    balance -> loadExpensesForSelectedPeriod(getExpensesOfUser());
    balance -> sortExpensesByDate();
    balance -> displayExpenses();
    balance -> displayCashflow();
    delete balance;
    balance = NULL;
    system("pause");

}

void IncomesExpensesManager::displayPreviousMonthBalance() {
    system("cls");
    balance = new Balance(date.getPreviousMonthStartDate(), date.getPreviousMonthEndDate());
    balance -> loadIncomesForSelectedPeriod(getIncomesOfUser());
    balance -> sortIncomesByDate();
    cout << "Bilans za okres " << date.getPreviousMonthStartDate() << " - " << date.getPreviousMonthEndDate() << endl;
    balance -> displayIncomes();
    balance -> loadExpensesForSelectedPeriod(getExpensesOfUser());
    balance -> sortExpensesByDate();
    balance -> displayExpenses();
    balance -> displayCashflow();
    delete balance;
    balance = NULL;
    system("pause");
}

vector<Income> IncomesExpensesManager::getIncomesOfUser() {
    return incomes;
}

vector<Expense> IncomesExpensesManager::getExpensesOfUser() {
    return expenses;
}
