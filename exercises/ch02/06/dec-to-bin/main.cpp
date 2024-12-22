#include <iostream>

using std::cin;
using std::cout;

int get_bit(int bits, int bitNum) {
    while (bitNum-- > 1) bits /= 2;
    return bits % 2;
}

int main() {

    char digit;
    int decimal = 0, bitsNum = 0;

    cout << "Enter a decimal digit: ";
 
    digit = cin.get();
    while (digit != 10) {
        decimal *= 10;
        decimal += (digit - '0');
        bitsNum += 4;
        digit = cin.get();
    }
    
    // Get rid of leading zeros
    while (get_bit(decimal, bitsNum) == 0) --bitsNum;

    cout << "The binary number is: ";
    
    while (bitsNum > 0) cout << get_bit(decimal, bitsNum--);
    
    cout << '\n';

    return 0;
    
}
