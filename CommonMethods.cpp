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
