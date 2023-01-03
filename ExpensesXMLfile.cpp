#include "ExpensesXMLfile.h"


void ExpensesXMLFile::saveExpensesToXMLfile(Expense newExpense) {
    CMarkup xmlDocument;
    xmlDocument.Load(EXPESNES_XML_FILE_NAME);
    if (xmlDocument.FindElem("expenses") == false) {
        xmlDocument.SetDoc("<?xml version='1.0'?>\n");
        xmlDocument.AddElem("expenses");
    }
    string amount = CommonMethods::convertFloatToString(newExpense.getAmount());
    xmlDocument.IntoElem();
    xmlDocument.AddElem("expense");
    xmlDocument.AddAttrib("expenseId", newExpense.getId());
    xmlDocument.AddAttrib("userId", newExpense.getUserId());
    xmlDocument.AddAttrib("date", newExpense.getDate());
    xmlDocument.IntoElem();
    xmlDocument.AddElem("item", newExpense.getItem());
    xmlDocument.AddElem("amount", amount);
    xmlDocument.Save(EXPESNES_XML_FILE_NAME);
}
