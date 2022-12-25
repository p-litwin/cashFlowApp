#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include "CommonMethods.h"

using namespace std;

class Date {
    string currentDate;
    int currentDay;
    int currentMonth;
    int currentYear;
    int currentMonthLength;

    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
    int daysInCurrentMonth();
    int getNumberOfDaysInMonth(int month, int year);

public:
    Date() {
        currentDate = determineCurrentDate();
        currentDay = getCurrentDay();
        currentMonth = getCurrentMonth();
        currentYear = getCurrentYear();
        currentMonthLength = getNumberOfDaysInMonth(currentMonth, currentYear);
    };
    string determineCurrentDate();

};


#endif // DATE_H
