#include "CommonMethods.h"

string CommonMethods::getLineOfText() {
    string lineOfText;
    cin.sync();
    getline(cin, lineOfText);
    return lineOfText;
}
