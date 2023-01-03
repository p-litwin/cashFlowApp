#include "IncomeExpense.h"

int IncomeExpense::getId() {
    return id;
}

int IncomeExpense::getUserId() {
    return userId;
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

void IncomeExpense::setUserId(int userId) {
    this -> userId = userId;
}
