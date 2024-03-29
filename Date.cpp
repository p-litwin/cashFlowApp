#include "Date.h"

string Date::determineCurrentDate() {

    int currentYear = determineCurrentYear();
    int currentMonth = determineCurrentMonth();
    int currentDay = determineCurrentDay();
    string currentYearAsText = CommonMethods::convertIntToStringWithLeadingZero(currentYear);
    string currentMonthAsText = CommonMethods::convertIntToStringWithLeadingZero(currentMonth);
    string currentDayAsText = CommonMethods::convertIntToStringWithLeadingZero(currentDay);
    string currentDateAsText = currentYearAsText + "-" + currentMonthAsText + "-" + currentDayAsText;
    return currentDateAsText;
}

int Date::determineCurrentYear () {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentYear = 1900 + pTInfo->tm_year;
    return currentYear;
}

int Date:: determineCurrentMonth() {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentMonth = 1 + pTInfo->tm_mon;
    return currentMonth;
}

int Date:: determineCurrentDay() {
    time_t t = time(0);
    tm *const pTInfo = localtime(&t);
    int currentDay = pTInfo->tm_mday;
    return currentDay;
}

int  Date::determineMonthLength(int year, int month) {
    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12) {
        return 31;
    } else {
        return 30;
    }
}

string Date::getDateFromUser() {
    string date;
    do {
        date = CommonMethods::getMandatoryLineOfText("Podaj date w formacie yyyy-mm-dd");
        if (isSelectedDateValid(date) == false) {
            cout << "Podana data ma nieprawidlowy format lub jest spoza zakresu 2000-01-01 - ostatni dzien biezacego miesiaca." << endl;
        }
    } while (isSelectedDateValid(date) == false);
    return date;
}

bool Date::isDateFormatCorrect(string date) {
    regex correctDateFormat("[2-9][0-9][0-9][0-9][-]([0][1-9]|[1][1-2])[-]([0][1-9]|[1-2][0-9]|[3][0-1])");
    if (regex_match(date, correctDateFormat)) {
        return true;
    }
    return false;
}

bool Date::isSelectedDateValid(string date) {

    if (isDateFormatCorrect(date) == false) {
        return false;
    }

    int inputYear = stoi(date.substr(0,4));
    int inputMonth = stoi(date.substr(5,6));
    int inputDay = stoi(date.substr(8,9));
    if (isInputYearCorrect(inputYear) && isInputMonthCorrect(inputYear, inputMonth) && isInputDayCorrect(inputYear, inputMonth, inputDay)) {
        return true;
    }
    return false;
}

bool Date::isInputMonthCorrect(int year, int month) {
    bool isMonthInCurrentYearCorrect = (year == determineCurrentYear() && month >= 1 && month <= determineCurrentMonth() );
    bool isMonthInEarlierYearCorrect = (year < determineCurrentYear() && month >= 1 && month <= 12);

    if ( isMonthInCurrentYearCorrect || isMonthInEarlierYearCorrect ) {
        return true;
    }
    return false;
}

bool Date::isInputYearCorrect(int year) {
    if (year >= 2000 && year <= determineCurrentYear()) {
        return true;
    }
    return false;
}

bool Date::isInputDayCorrect(int year,int month, int day) {
    if (day >= 1 && day <= determineMonthLength(year,  month)) {
        return true;
    }
    return false;
}

string Date::getCurrentMonthStartDate() {
    int currentMonth = determineCurrentMonth();
    int currentYear = determineCurrentYear();
    string startDateOfCurrentMonth = to_string(currentYear) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth) + "-01";
    return startDateOfCurrentMonth;
}
string Date::getCurrentMonthEndDate() {
    int currentMonth = determineCurrentMonth();
    int currentYear = determineCurrentYear();
    int currentMonthLength = determineMonthLength(currentYear, currentMonth);
    string endDateOfCurrentMonth = to_string(currentYear) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth) + "-" + to_string(currentMonthLength);
    return endDateOfCurrentMonth;
}

string Date::getPreviousMonthStartDate() {
    string startDateOfPreviousMonth;
    int currentMonth = determineCurrentMonth();
    int currentYear = determineCurrentYear();
    if (currentMonth == 1) {
        startDateOfPreviousMonth = to_string(currentYear - 1) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth + 11 ) + "-01";
    } else {
        startDateOfPreviousMonth = to_string(currentYear) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth - 1) + "-01";
    }
    return startDateOfPreviousMonth;
}
string Date::getPreviousMonthEndDate() {
    string endDateOfPreviousMonth;
    int currentMonth = determineCurrentMonth();
    int currentYear = determineCurrentYear();
    if (currentMonth == 1) {
        endDateOfPreviousMonth = to_string(currentYear - 1) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth + 11 ) + "-31";
    } else {
        endDateOfPreviousMonth = to_string(currentYear) + "-" + CommonMethods::convertIntToStringWithLeadingZero(currentMonth - 1) + "-" + to_string(determineMonthLength(currentYear, currentMonth - 1));
    }
    return endDateOfPreviousMonth;
}
