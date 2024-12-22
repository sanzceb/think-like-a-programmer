#include <iostream>

using std::cin;
using std::cout;

int main() {
    const char CIPHER_ALPHABET[] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
        'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'
    };

    cout << "Input a plaintext, I will cipher it!: ";
    char character = cin.get();
    while (character != '\n') {
        // if (character is an UPPERCASE letter)
        if ('A' <= character && 'Z' >= character) {
            character = CIPHER_ALPHABET[character - 'A'];
        }
        cout << character;
        character = cin.get();
    }

    cout << character;
}