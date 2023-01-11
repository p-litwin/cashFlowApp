#ifndef BALANCE_H
#define BALANCE_H

#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include <algorithm>

class Balance {
    vector<Income> incomes;
    vector<Expense> expenses;
    const string START_DATE;
    const string END_DATE;
    float totalIncomes;
    float totalExpenses;
    float cashflow;
    static bool dateCompareIncome (Income income1, Income income2);
    static bool dateCompareExpense (Expense expense1, Expense expense2);


public:
    Balance(string startDate, string endDate)
    :START_DATE(startDate), END_DATE(endDate){
    };
    void loadIncomesForSelectedPeriod(vector<Income> userIncomes);
    void loadExpensesForSelectedPeriod(vector<Expense> userExpenses);
    void displayExpenses();
    void displayIncomes();
    void sortExpensesByDate();
    void sortIncomesByDate();
};

#endif // BALANCE_H
