#ifndef INCOMESEXPENSESMANAGER_H
#define INCOMESEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Date.h"
#include "ExpensesXMLfile.h"
#include "IncomesXMLfile.h"
#include "Balance.h"

using namespace std;

class IncomesExpensesManager {
    const int LOGGED_USER_ID;
    Date date;
    vector<Income> incomes;
    vector<Expense> expenses;
    int lastIncomeId;
    int lastExpenseId;
    IncomesXMLfile *incomesXMLfile;
    ExpensesXMLfile *expensesXMLfile;
    Balance *balance;

    Income readSingleIncomeFromXML(CMarkup *xmlDocument);
    Expense readSingleExpenseFromXML(CMarkup *xmlDocument);

public:
    IncomesExpensesManager(int loggedUserId)
    : LOGGED_USER_ID(loggedUserId) {
        lastIncomeId = 0;
        lastExpenseId = 0;
        incomesXMLfile = new IncomesXMLfile("incomes.xml");
        expensesXMLfile = new ExpensesXMLfile("expenses.xml");
        loadIncomesForLoggedUser(incomesXMLfile -> getXMLdocument());
        loadExpensesForLoggedUser(expensesXMLfile -> getXMLdocument());
    };
    ~IncomesExpensesManager() {
        delete incomesXMLfile;
        delete expensesXMLfile;
        delete balance;
        incomesXMLfile = NULL;
        expensesXMLfile = NULL;
        balance = NULL;
    }
    void addNewExpense();
    void addNewIncome();
    void loadIncomesForLoggedUser(CMarkup *xmlDocument);
    void loadExpensesForLoggedUser(CMarkup *xmlDocument);
    void displayExpense(int index);
    void displayIncome(int index);
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayCustomPeriodBalance();
    vector<Income> getIncomesOfUser();
    vector<Expense> getExpensesOfUser();

};


#endif // INCOMESEXPENSESMANAGER_H
