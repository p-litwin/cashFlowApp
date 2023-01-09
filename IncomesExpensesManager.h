#ifndef INCOMESEXPENSESMANAGER_H
#define INCOMESEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Date.h"
#include "ExpensesXMLfile.h"
#include "IncomesXMLfile.h"

using namespace std;

class IncomesExpensesManager {
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    Date date;
    int lastIncomeId;
    int lastExpenseId;
    float totalIncomes;
    float totalExpenses;
    float balance;
    IncomesXMLfile *incomesXMLfile;
    ExpensesXMLfile *expensesXMLfile;

public:
    IncomesExpensesManager(int loggedUserId)
    : LOGGED_USER_ID(loggedUserId) {
        lastIncomeId = 0;
        lastExpenseId = 0;
        incomesXMLfile = new IncomesXMLfile("incomes.xml");
        expensesXMLfile = new ExpensesXMLfile("expenses.xml");
    };
    ~IncomesExpensesManager() {
        delete incomesXMLfile;
        delete expensesXMLfile;
        incomesXMLfile = NULL;
        expensesXMLfile = NULL;
    }
    void addNewExpense();
    void addNewIncome();
    void displayExpense(int index);
    void displayIncome(int index);

};


#endif // INCOMESEXPENSESMANAGER_H
