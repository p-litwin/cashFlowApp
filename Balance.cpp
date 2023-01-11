#include "Balance.h"

void Balance::loadIncomesForSelectedPeriod(CMarkup xmlDocument){
    Income singleIncome;
    CMarkup *xmlPTR = &xmlDocument;
    xmlDocument.FindElem("incomes");
    xmlDocument.IntoElem();

    while (xmlDocument.FindElem("income")) {
        if (stoi(xmlDocument.GetAttrib("userId")) == 2 && ( xmlDocument.GetAttrib("date") >= START_DATE && xmlDocument.GetAttrib("date") <= END_DATE)) {
            singleIncome = readSingleIncomeFromXML(xmlPTR);
            incomes.push_back(singleIncome);
        }
    }
}
void Balance::loadExpensesForSelectedPeriod(CMarkup xmlDocument){
    Expense singleExpense;
    CMarkup *xmlPTR = &xmlDocument;
    xmlDocument.FindElem("expenses");
    xmlDocument.IntoElem();

    while (xmlDocument.FindElem("expense")) {
        if (stoi(xmlDocument.GetAttrib("userId")) == 2 && ( xmlDocument.GetAttrib("date") >= START_DATE && xmlDocument.GetAttrib("date") <= END_DATE)) {
            singleExpense = readSingleExpenseFromXML(xmlPTR);
            expenses.push_back(singleExpense);
        }
    }
}

Income Balance::readSingleIncomeFromXML(CMarkup *xmlDocument) {
    Income income;
    income.setId(stoi(xmlDocument -> GetAttrib("incomeId")));
    income.setDate(xmlDocument -> GetAttrib("date"));
    xmlDocument -> FindChildElem("item");
    xmlDocument -> IntoElem();
    income.setItem(xmlDocument -> GetData());
    xmlDocument -> OutOfElem();
    xmlDocument -> FindChildElem("amount");
    xmlDocument -> IntoElem();
    income.setAmount(stof(xmlDocument -> GetData()));
    xmlDocument -> OutOfElem();
    return income;
}

Expense Balance::readSingleExpenseFromXML(CMarkup *xmlDocument) {
    Expense expense;
    expense.setId(stoi(xmlDocument -> GetAttrib("expenseId")));
    expense.setDate(xmlDocument -> GetAttrib("date"));
    xmlDocument -> FindChildElem("item");
    xmlDocument -> IntoElem();
    expense.setItem(xmlDocument -> GetData());
    xmlDocument -> OutOfElem();
    xmlDocument -> FindChildElem("amount");
    xmlDocument -> IntoElem();
    expense.setAmount(stof(xmlDocument -> GetData()));
    xmlDocument -> OutOfElem();
    return expense;
}

void Balance::displayExpense(int index) {
cout << expenses.size() << endl;
system("pause");
//    cout << expenses[index].getId() << endl;
//    cout << expenses[index].getDate() << endl;
//    cout << expenses[index].getItem() << endl;
//    cout << expenses[index].getAmount() << endl;
}

void Balance::displayIncome(int index) {
cout << incomes.size() << endl;
system("pause");
//    cout << incomes[index].getId() << endl;
//    cout << incomes[index].getDate() << endl;
//    cout << incomes[index].getItem() << endl;
//    cout << incomes[index].getAmount() << endl;
}
