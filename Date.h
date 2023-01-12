#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <regex>
#include "CommonMethods.h"

using namespace std;

class Date {
    string currentDate;
    string startDateOfCurrentMonth;
    string endDateOfCurrentMonth;
    string startDateOfLastMonth;
    string endDateOfLastMonth;
    int currentDay;
    int currentMonth;
    int currentYear;
    int currentMonthLength;
    int lastMonthLenght;

    int determineCurrentDay();
    int determineCurrentMonth();
    int determineCurrentYear();
    int determineMonthLength(int month, int year);
    bool isSelectedDateValid(string date);
    bool isDateFormatCorrect(string date);
    bool isInputMonthCorrect(int year, int month);
    bool isInputYearCorrect(int year);
    bool isInputDayCorrect(int year,int month, int day);
public:
    Date() {
        currentDate = determineCurrentDate();
        currentDay = determineCurrentDay();
        currentMonth = determineCurrentMonth();
        currentYear = determineCurrentYear();
        currentMonthLength = determineMonthLength(currentMonth, currentYear);
    };
    string determineCurrentDate();
    string getCurrentDate();
    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
    string getDateFromUser();
    string getcurrentMonthStartDate();
    string getCurrentMonthEndDate();
    string getPreviousMonthStartDate();
    string getPreviousMonthEndDate();
};


#endif // DATE_H
