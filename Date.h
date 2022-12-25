#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include "CommonMethods.h"

using namespace std;

class Date {
    string currentDate;

    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
public:
    string determineCurrentDate();

};


#endif // DATE_H
