#include <iostream>

using std::cin;
using std::cout;

int as_decimal(char digit) {
    if (digit >= 97) return 10 + (digit - 'a');
    else if (digit >= 65) return 10 + (digit - 'A');
    else return digit - '0';
}

char get_base_digit(int decimal, int digitNum, int base) {
    while (digitNum-- > 1) decimal /= base;
    int digit = decimal % base;
    if (digit < 10) return digit + '0';
    else return (digit - 10) + 'a';
}

int main() {
    int decimal = 0, base = 0, digitsNum = 0;
    char digit;

    cout << "Enter the base of the input: ";
 
    digit = cin.get();
    while (digit != 10) {
        base *= 10;
        base += as_decimal(digit);
        digit = cin.get();
    }

    cout << "Enter the number in base " 
        << base << ": ";
    
    digit = cin.get();
    while (digit != 10) {
        decimal *= base;
        decimal += as_decimal(digit);
        cin.get(digit);
        ++digitsNum;
    }
    
    cout << "Enter the base of the output: ";
    cin >> base;

    cout << "The number in base "
         << base << " is: ";
    
     // For smaller bases we need to expand the number of digits  
    if (base == 2) digitsNum *= 4;
    else if (base == 3) digitsNum *= 3;
    else if (base < 10) digitsNum *= 2;

    // Get rid of leading zeros
    while (get_base_digit(decimal, digitsNum, base) == '0') --digitsNum;
        
    // Compute the output digit
    while (digitsNum > 0) cout << get_base_digit(decimal, digitsNum--, base);    

    cout << '\n';

    return 0;
}