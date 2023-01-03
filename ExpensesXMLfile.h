#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H

#include <iostream>
#include "Markup.h"
#include "Expense.h"
#include "CommonMethods.h"

using namespace std;

class ExpensesXMLFile {
    const string EXPESNES_XML_FILE_NAME;

public:
    ExpensesXMLFile(string fileName)
        : EXPESNES_XML_FILE_NAME(fileName) {
    };

    void saveExpensesToXMLfile(Expense newExpense);
};


#endif // EXPENSESXMLFILE_H
