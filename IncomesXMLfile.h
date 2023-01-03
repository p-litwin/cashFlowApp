#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include "Markup.h"
#include "Income.h"
#include "CommonMethods.h"

using namespace std;

class IncomesXMLFile {
    const string INCOMES_XML_FILE_NAME;

public:
    IncomesXMLFile(string fileName)
        : INCOMES_XML_FILE_NAME(fileName) {
    };

    void saveIncomesToXMLfile(Income newIncome);
};


#endif // INCOMESXMLFILE_H
