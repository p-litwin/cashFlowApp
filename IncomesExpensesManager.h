#ifndef INCOMESEXPENSESMANAGER_H
#define INCOMESEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"

using namespace std;

class IncomesExpensesManager {
    vector<Income> incomes;
    vector<Expense> expenses;
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
    Expense addNewExpense();

};


#endif // INCOMESEXPENSESMANAGER_H
