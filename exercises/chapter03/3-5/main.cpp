#include <iostream>

using std::cout;
using std::cin;

int main() {
    const int CIPHER_ALPHABET_SIZE = 26;
    const char CIPHER_ALPHABET[CIPHER_ALPHABET_SIZE] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
        'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'
    };

    cout << "Input a cipher text. I will decipher it!: ";
    char character = cin.get();
    while (character != '\n') {
        // if (character is UPPERCASE) decipher it
        if ('A' <= character && 'Z' >= character) {
            // Basic Array OP: Search the cipher code
            int cipherCode = 0;
            while (cipherCode < CIPHER_ALPHABET_SIZE && 
                CIPHER_ALPHABET[cipherCode] != character) {
                cipherCode++;        
            }
            character = ('A' + cipherCode);
        }
        cout << character; 
        character = cin.get();
    }
    cout << character;

    return 0;
}
