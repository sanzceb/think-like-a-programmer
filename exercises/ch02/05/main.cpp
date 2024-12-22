#include <iostream>

using std::cin;
using std::cout;

int isbn_multiplication(char digit, int position) {
    if (position % 2 == 0) return 3 * (digit - '0');
    else return digit - '0';
}

int checksum_calculation(int sum) {
    return (10 - (sum % 10)) % 10;
}

int main() {
    char character;
    int sum = 0, check_digit;
    int position = 1;

    cout << "Input a ISBN code: ";

    character = cin.get();
    while (character != 10) {
        if (character != 32 && character != 45) {
            if (position < 13) {
                sum += isbn_multiplication(character, position);
            }
            else {
                check_digit = character - '0';
            }
            position++;
        }
        character = cin.get();
    }

    if (position != 14) {
        cout << "Error: The length is invalid.\n";
        return 1;
    }

    int checksum = checksum_calculation(sum);
    cout << "The checksum is " << checksum
        << " and the check digit is " << check_digit;
    
    if (check_digit == checksum) cout << ". Valid.\n";
    else cout << ". Invalid.\n";

    return 0;
}
