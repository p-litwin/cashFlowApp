#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <iostream>
#include <regex>
#include <sstream>
#include <iomanip>

using namespace std;

class CommonMethods {

public:
    static string getLineOfText();
    static char getSingleCharacter();
    static string convertIntToStringWithLeadingZero(int number);
    static string getMandatoryLineOfText(string prompt);
    static float getMandatoryFloatValue();
    static bool isInputValidFloatWithComma(string input);
    static bool isInputValidFloatWithDot(string input);
    static float convertStringToFloat(string input);
    static string convertFloatToString(float number);
};


#endif // COMMONMETHODS_H
