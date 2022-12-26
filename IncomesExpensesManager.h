#ifndef INCOMESEXPENSESMANAGER_H
#define INCOMESEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Date.h"

using namespace std;

class IncomesExpensesManager {
    int loggedUserId;
    vector<Income> incomes;
    vector<Expense> expenses;
    Date date;
    int lastIncomeId;
    int lastExpenseId;
    float totalIncomes;
    float totalExpenses;
    float balance;

public:
    IncomesExpensesManager() {
        lastIncomeId = 0;
        lastExpenseId = 0;
    };
    Income addNewIncome();
    void addNewExpense();
    void displayExpense(int index);
    int setLoggedUserId(int id);

};


#endif // INCOMESEXPENSESMANAGER_H
