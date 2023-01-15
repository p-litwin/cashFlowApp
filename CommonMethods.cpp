#include "CommonMethods.h"

string CommonMethods::getLineOfText() {
    string lineOfText;
    cin.sync();
    getline(cin, lineOfText);
    return lineOfText;
}

char CommonMethods::getSingleCharacter() {

    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string CommonMethods::convertIntToStringWithLeadingZero(int number) {
    string numberAsText;
    if (number < 10) {
        numberAsText = "0" + to_string(number);
    } else {
        numberAsText = to_string(number);
    }
    return numberAsText;
}

string CommonMethods::getMandatoryLineOfText(string prompt) {
    string lineOfText = "";
    cout << prompt << ": ";
    cin.sync();
    while(true) {
        getline(cin,lineOfText);
        if (lineOfText.length() == 0) {
            cout << "Tekst nie moze byc pusty. Wprowadz wartosc." << endl;
        } else {
            return lineOfText;
        }
    }
}

float CommonMethods::getMandatoryFloatValue() {
    string input = "";
    float amount = 0.0;
    while(true) {
        input = getMandatoryLineOfText("Podaj kwote (max. 2 miejsca po przecinku)");
        if (isInputValidFloatWithComma(input) || isInputValidFloatWithDot(input)) {
            amount = convertStringToFloat(input);
            return amount;
        } else {
            cout << "Podana wartosc jest nieprawidlowa. Liczba musi miec maksymalnie 2 miejsca po przecinknu." << endl;
        }
    }
    return amount;
}

bool CommonMethods::isInputValidFloatWithComma(string input) {
    regex floatWithComma("([0-9]*[,])?[0-9][0-9]");
    if (regex_match(input, floatWithComma)) {
        return true;
    }
    return false;
}

bool CommonMethods::isInputValidFloatWithDot(string input) {
    regex floatWithDot("([0-9]*[.])?[0-9][0-9]");
    if (regex_match(input, floatWithDot)) {
        return true;
    }
    return false;
}

float CommonMethods::convertStringToFloat(string input) {
    regex floatWithDot("([0-9]*[.])?[0-9]+");
    regex floatWithComma("([0-9]*[,])?[0-9]+");
    if (regex_match(input, floatWithDot)) {
        return stof(input);
    } else if (regex_match(input, floatWithComma)) {
        replace(input.begin(), input.end(),',','.');
        return stof(input);
    }
}

string CommonMethods::convertFloatToString(float number) {
    stringstream floatAsString;
    floatAsString << fixed << setprecision(2) << number;
    return floatAsString.str();
}
