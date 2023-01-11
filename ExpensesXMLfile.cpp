#include "ExpensesXMLfile.h"


void ExpensesXMLfile::addNewExpenseToXMLdocument(Expense newExpense) {
    xmlDocument.ResetPos();
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
}
