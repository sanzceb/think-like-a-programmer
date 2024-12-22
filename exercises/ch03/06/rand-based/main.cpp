#include <iostream>

using std::cout;
using std::cin;

bool arrayHasTarget(char target, const char charArray[], int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (charArray[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    const int ALPHABET_SIZE = 26;
    char cipherArray[ALPHABET_SIZE];

    // NEW random sequence
    srand(time(nullptr));

    for (int i = 0; i < ALPHABET_SIZE; i++) {      
        char charToSubstitute = ('A' + i);        
        char newSubstitute; 

        // newSubstitute = NEW random substitute
        do newSubstitute = 'A' + (rand() % ALPHABET_SIZE);
        while ((newSubstitute == charToSubstitute) || 
            arrayHasTarget(newSubstitute, cipherArray, i));

        cipherArray[i] = newSubstitute;
    }

    cout << "Plain text:    ";
    char character = cin.get();
    cout << "Ciphered text: ";
    while (character != '\n') {
        // if (character IS Uppercase)
        if ('A' <= character && 'Z' >= character) {
            // character = LOOKUP character cipher
            character = cipherArray[character - 'A'];
        }
        cout << character;
        character = cin.get();
    }
    cout << character;

    return 0;
}