#ifndef BALANCE_H
#define BALANCE_H

#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"

class Balance {
    vector<Income> incomes;
    vector<Expense> expenses;
    const string START_DATE;
    const string END_DATE;
    float totalIncomes;
    float totalExpenses;
    float cashflow;
public:
    Balance(string startDate, string endDate)
    :START_DATE(startDate), END_DATE(endDate){
    };
    void loadIncomesForSelectedPeriod(CMarkup xmlDocument);
    void loadExpensesForSelectedPeriod(CMarkup xmlDocument);
    Income readSingleIncomeFromXML(CMarkup *xmlDocument);
    Expense readSingleExpenseFromXML(CMarkup *xmlDocument);
    void loadExpensesForSelectedPeriod();
    void displayExpense(int index);
    void displayIncome(int index);
};

#endif // BALANCE_H
