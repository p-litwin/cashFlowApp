#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <regex>
#include "CommonMethods.h"

using namespace std;

class Date {
    static int determineCurrentDay();
    static int determineCurrentMonth();
    static int determineCurrentYear();
    static int determineMonthLength(int year, int month);
    static bool isSelectedDateValid(string date);
    static bool isDateFormatCorrect(string date);
    static bool isInputMonthCorrect(int year, int month);
    static bool isInputYearCorrect(int year);
    static bool isInputDayCorrect(int year,int month, int day);
public:
    static string determineCurrentDate();
    static string getDateFromUser();
    static string getCurrentMonthStartDate();
    static string getCurrentMonthEndDate();
    static string getPreviousMonthStartDate();
    static string getPreviousMonthEndDate();
};


#endif // DATE_H
