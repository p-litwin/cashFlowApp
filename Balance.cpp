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
    cout << "=============================================================" << endl;
    cout << "=========================Wydatki=============================" << endl;
    cout << "=============================================================" << endl;
    cout << setw(16) << left << "Data" << setw(36) << left << "Kategoria wydatku" << setw(8) << left << "Kwota" << endl;
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << setw(16) << left << expenses[i].getDate() << setw(36) << left << expenses[i].getItem() << setw(8) << left << expenses[i].getAmount() << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << setw(16) << left << " " << setw(36) << left <<  "Suma wydatkow:" << setw(8) << left << "2500,00" << endl << endl;
}

void Balance::displayIncomes() {
    cout << "=============================================================" << endl;
    cout << "=========================Przychody===========================" << endl;
    cout << "=============================================================" << endl;
    cout << setw(16) << left << "Data" << setw(36) << left << "Kategoria przychodu" << setw(8) << left << "Kwota" << endl;
    for (size_t i = 0; i < incomes.size(); i++) {
        cout << setw(16) << left << incomes[i].getDate() << setw(36) << left << incomes[i].getItem() << setw(8) << left << incomes[i].getAmount() << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << setw(16) << left << " " << setw(36) << left <<  "Suma przychodow:" << setw(8) << left << "2500,00" << endl << endl;
}

bool Balance::dateCompareIncome (Income income1, Income income2) {
    return (income1.getDate() < income2.getDate()) ;
}

bool Balance::dateCompareExpense (Expense expense1, Expense expense2) {
    return (expense1.getDate() < expense2.getDate()) ;
}

void Balance::sortExpensesByDate() {
    sort(expenses.begin(), expenses.end(),dateCompareExpense);
}
void Balance::sortIncomesByDate() {
    sort(incomes.begin(), incomes.end(),dateCompareIncome);
}
