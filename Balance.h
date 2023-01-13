#ifndef BALANCE_H
#define BALANCE_H

#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include <algorithm>
#include <iomanip>

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
    void addToTotalExpenses(float amount);
    void addToTotalIncomes(float amount);
    void calculateCashflow();



public:
    Balance(string startDate, string endDate)
    :START_DATE(startDate), END_DATE(endDate){
    totalExpenses = 0.0;
    totalIncomes = 0.0;
    cashflow = 0.0;
    };
    void loadIncomesForSelectedPeriod(vector<Income> userIncomes);
    void loadExpensesForSelectedPeriod(vector<Expense> userExpenses);
    void displayExpenses();
    void displayIncomes();
    void sortExpensesByDate();
    void sortIncomesByDate();
    void displayCashflow();
};

#endif // BALANCE_H
