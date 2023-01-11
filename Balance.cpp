#include "Balance.h"

void Balance::loadIncomesForSelectedPeriod(vector<Income> userIncomes) {
    for (size_t i = 0; i < userIncomes.size(); i++) {
        if (userIncomes[i].getDate() >= START_DATE && userIncomes[i].getDate() <= END_DATE) {
            incomes.push_back(userIncomes[i]);
        }
    }
}

void Balance::loadExpensesForSelectedPeriod(vector<Expense> userExpenses) {
    for (size_t i = 0; i < userExpenses.size(); i++) {
        if (userExpenses[i].getDate() >= START_DATE && userExpenses[i].getDate() <= END_DATE) {
            expenses.push_back(userExpenses[i]);
        }
    }
}

void Balance::displayExpenses() {
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << expenses[i].getId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
    }
}

void Balance::displayIncomes() {
    for (size_t i = 0; i < incomes.size(); i++) {
        cout << incomes[i].getId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
}

bool Balance::dateCompareIncome (Income income1, Income income2) {
    return (income1.getDate() < income2.getDate()) ;
}

bool Balance::dateCompareExpense (Expense expense1, Expense expense2) {
    return (expense1.getDate() < expense2.getDate()) ;
}

void Balance::sortExpensesByDate(){
    sort(expenses.begin(), expenses.end(),dateCompareExpense);
}
void Balance::sortIncomesByDate(){
    sort(incomes.begin(), incomes.end(),dateCompareIncome);
}
