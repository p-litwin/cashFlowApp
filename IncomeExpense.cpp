#include "IncomeExpense.h"

int IncomeExpense::getId() {
    return id;
}
string IncomeExpense::getDate() {
    return date;
}
string IncomeExpense::getItem() {
    return item;
}
float IncomeExpense::getAmount() {
    return amount;
}
void IncomeExpense::setId(int id) {
    this -> id = id;
}
void IncomeExpense::setDate(string date) {
    this -> date = date;
}
void IncomeExpense::setItem(string item) {
    this -> item = item;
}
void IncomeExpense::setAmount(float amount) {
    this -> amount = amount;
}

void IncomeExpense::setUserId(int userIsd) {
    this -> userId = id;
}
