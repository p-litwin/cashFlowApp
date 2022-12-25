#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <iostream>

using namespace std;

class CommonMethods {

public:
    static string getLineOfText();
    static char getSingleCharacter();
    static string getCurrentDate();
    static string convertIntToStringWithLeadingZero(int number);
};


#endif // COMMONMETHODS_H
