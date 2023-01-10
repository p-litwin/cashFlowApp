#ifndef BALANCE_H
#define BALANCE_H

#include <vector>
#include "Income.h"
#include "Expense.h"

class Balance {
    vector<Income> incomes;
    vector<Expense> expenses;
    string startDate;
    string endDate;
    float totalIncomes;
    float totalExpenses;
    float cashflow;
public:
    Balance(){};
    void displayExpense(int index);
    void displayIncome(int index);
};

#endif // BALANCE_H
