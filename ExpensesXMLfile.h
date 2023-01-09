#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H

#include <iostream>
#include "Markup.h"
#include "Expense.h"
#include "CommonMethods.h"
#include "XMLfile.h"

using namespace std;

class ExpensesXMLfile:public XMLfile {

public:
    ExpensesXMLfile(string fileName)
    :XMLfile(fileName) {
    };
    void addNewExpenseToXMLdocument(Expense newExpense);
};


#endif // EXPENSESXMLFILE_H
