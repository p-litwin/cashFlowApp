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
    if (number < 9) {
        numberAsText = "0" + to_string(number);
    } else {
        numberAsText = to_string(number);
    }
    return numberAsText;
}
