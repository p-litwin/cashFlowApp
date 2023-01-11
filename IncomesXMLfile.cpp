#include "IncomesXMLfile.h"


void IncomesXMLfile::addNewIncomeToXMLdocument(Income newIncome) {
    xmlDocument.ResetPos();
    if (xmlDocument.FindElem("incomes") == false) {
        xmlDocument.SetDoc("<?xml version='1.0'?>\n");
        xmlDocument.AddElem("incomes");
    }
    string amount = CommonMethods::convertFloatToString(newIncome.getAmount());
    xmlDocument.IntoElem();
    xmlDocument.AddElem("income");
    xmlDocument.AddAttrib("incomeId", newIncome.getId());
    xmlDocument.AddAttrib("userId", newIncome.getUserId());
    xmlDocument.AddAttrib("date", newIncome.getDate());
    xmlDocument.IntoElem();
    xmlDocument.AddElem("item", newIncome.getItem());
    xmlDocument.AddElem("amount", amount);
}
