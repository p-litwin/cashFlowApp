#include "Date.h"

string Date::determineCurrentDate() {

    int currentYear = getCurrentYear();
    int currentMonth = getCurrentMonth();
    int currentDay = getCurrentDay();
    string currentYearAsText = CommonMethods::convertIntToStringWithLeadingZero(currentYear);
    string currentMonthAsText = CommonMethods::convertIntToStringWithLeadingZero(currentMonth);
    string currentDayAsText = CommonMethods::convertIntToStringWithLeadingZero(currentDay);
    string currentDateAsText = currentYearAsText + "-" + currentMonthAsText + "-" + currentDayAsText;
    return currentDateAsText;
}

int Date::getCurrentYear () {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentYear = 1900 + pTInfo->tm_year;
    return currentYear;
}

int Date:: getCurrentMonth() {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentMonth = 1 + pTInfo->tm_mon;
    return currentMonth;
}

int Date:: getCurrentDay() {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentDay = pTInfo->tm_mday;
    return currentDay;
}

int  Date::getNumberOfDaysInMonth(int month, int year) {
    //leap year condition, if month is 2
    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    //months which has 31 days
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}
