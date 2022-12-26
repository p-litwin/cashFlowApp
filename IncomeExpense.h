#ifndef INCOMEEXPENSE_H
#define INCOMEEXPENSE_H

#include <iostream>

using namespace std;

class IncomeExpense {
protected:
    int id;
    int userId;
    string date;
    string item;
    float amount;

public:
    IncomeExpense(){};
    int getId();
    string getDate();
    string getItem();
    float getAmount();
    void setUserId(int userId);
    void setId(int id);
    void setDate(string date);
    void setItem(string item);
    void setAmount(float amount);
};


#endif // INCOMEEXPENSE_H
