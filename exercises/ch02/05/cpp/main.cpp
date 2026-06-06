#include <iostream>

using std::cin;
using std::cout;

int multiply_isbn_digit(char digit, int position) {
    if (position % 2 == 0) return 3 * (digit - '0');
    else return digit - '0';
}

int main() {
    char character;
    int checksum = 0;
    int position = 1;

    cout << "Input a ISBN code: ";

    character = cin.get();
    while (character != 10) {
        if (character != 32 && character != 45) {
            if (position <= 13) {
                checksum += multiply_isbn_digit(character, position);
            }
            position++;
        }
        character = cin.get();
    }

    if (position != 14) {
        cout << "Error: The length is invalid.\n";
        return 1;
    }

    if (checksum % 10 == 0) cout << " The code is valid.\n";
    else cout << " The code is invalid.\n";

    return 0;
}
