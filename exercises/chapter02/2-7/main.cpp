#include <iostream>

using std::cin;
using std::cout;

int as_decimal(char digit) {
    if (digit >= 97) return 10 + (digit - 'a');
    else if (digit >= 65) return 10 + (digit - 'A');
    else return digit - '0';
}

int get_bit(int bits, int bitNum) {
    while (bitNum-- > 1) bits /= 2;
    return bits % 2;
}

char get_hex(int decimal, int hexNum) {
    while (hexNum -- > 1) decimal /= 16;
    int digit = decimal % 16;
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
        digit = cin.get();
        ++digitsNum;
    }
    
    cout << "Enter the base of the output: ";
    cin >> base;

    cout << "The number in base "
         << base << " is: ";
    
    if (base == 2) {

        for  (digitsNum *= 4; get_bit(decimal, digitsNum) == 0; --digitsNum);       
        
        while (digitsNum > 0) cout << get_bit(decimal, digitsNum--);

    } else if (base == 16) {

        while (get_hex(decimal, digitsNum) == '0') --digitsNum;
        
        while (digitsNum > 0) cout << get_hex(decimal, digitsNum--);
        
    } else {
        cout << decimal;
    }
    
    cout << '\n';

    return 0;
}