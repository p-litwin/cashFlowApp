#include "IncomesExpensesManager.h"

void IncomesExpensesManager::addNewExpense() {
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
    newExpense.setUserId(loggedUserId);
    newExpense.setItem(item);
    newExpense.setAmount(amount);
    newExpense.setId(++lastExpenseId);
    expenses.push_back(newExpense);
    cout << "Nowy wydatek zostal dodany." << endl;
    system("pause");
}

void IncomesExpensesManager::addNewIncome() {
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
    newIncome.setUserId(loggedUserId);
    newIncome.setItem(item);
    newIncome.setAmount(amount);
    newIncome.setId(++lastIncomeId);
    incomes.push_back(newIncome);
    cout << "Nowy wydatek zostal dodany." << endl;
    system("pause");
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

int IncomesExpensesManager::setLoggedUserId(int id) {
    this -> loggedUserId = id;
}
