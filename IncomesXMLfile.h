#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include "Markup.h"
#include "Income.h"
#include "CommonMethods.h"
#include "XMLfile.h"

using namespace std;

class IncomesXMLfile:public XMLfile {

public:
    IncomesXMLfile(string fileName)
    :XMLfile(fileName) {
    };
    void addNewIncomeToXMLdocument(Income newIncome);
};


#endif // INCOMESXMLFILE_H
