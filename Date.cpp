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
