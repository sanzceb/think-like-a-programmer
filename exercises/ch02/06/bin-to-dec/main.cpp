#include <iostream>

using std::cin;
using std::cout;

int main() {
    int decimal = 0;
    char bit;

    cout << "Input a binary number: ";
    
    bit = cin.get();
    while (bit != 10) {
        decimal *= 2;
        decimal += (bit - '0');
        cin.get(bit);
    }
    
    cout << "The binary number in decimal is: " << decimal << "\n";
    
    return 0;
}