#include <iostream>

using std::cin;
using std::cout;
using std::vector;

// Constants
const int ALPHABET_SIZE = 26, PUNCTUATIONS_SIZE = 9, VOWELS_SIZE = 5;
const char PUNCTUATIONS[PUNCTUATIONS_SIZE] = {
    '!', '?', ',', '.', ' ', ';', '"', '\'', '\n'
};
const char VOWELS[VOWELS_SIZE] = {'A', 'E', 'I', 'O', 'U'};

// Convenient Functions
bool arrayHasTarget(char target, const char charArray[], int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (charArray[i] == target) {
            return true;
        }
    }
    return false;
}

bool isUppercase(char character) {
    return 'A' <= character && 'Z' >= character;
}

bool isVowel(char character) {
    return arrayHasTarget(character, VOWELS, VOWELS_SIZE);
}

bool isPunctuation(char character) {
    return arrayHasTarget(character, PUNCTUATIONS, PUNCTUATIONS_SIZE);
}

// Start of the program

int main() {
    // Input State Tracking
    enum modeType {UPPERCASE, PUNCTUATION}; 
    modeType mode = PUNCTUATION;
    char character;
    
    // Ciphering
    char cipherArray[ALPHABET_SIZE]; 
    int seed = 0;

    // Statistics
    int wordCount = 0;
    int maxWordLen = 0, maxVowelCount = 0;
    int wordLen= 0, vowelCount = 0;
    
    // Input Storage
    vector <char> plainText;     
    plainText.reserve(50);
    int plainTextSize;

    cout << "Enter a line of text: ";
    do {
        character = cin.get();
        plainText.push_back(character);
        switch (mode) {
            case UPPERCASE:
                if (isUppercase(character)) {
                    if (isVowel(character)) vowelCount++;
                    wordLen++;                    
                } else if (isPunctuation(character)){
                    // UPDATE maxStats
                    if (wordLen > maxWordLen) maxWordLen = wordLen; 
                    if (vowelCount > maxVowelCount) maxVowelCount = vowelCount;
                    mode = PUNCTUATION;
                }
                break;
            case PUNCTUATION:
                if (isUppercase(character)) {
                    // INIT wordStats
                    wordCount++;
                    wordLen = 1;                    
                    if (isVowel(character)) vowelCount = 1;
                    else vowelCount = 0;
                    mode = UPPERCASE;
                }
                break;
            }
    } while (character != 10);

    // NEW random sequence
    seed = wordCount + maxWordLen + maxVowelCount;
    
    // RETRIEVE uppercaseArray and STORE cipherArray
    for (int charNum = 0; charNum < ALPHABET_SIZE; charNum++) {      
        char charToSubstitute = ('A' + charNum);        
        char newSubstitute; 

        // newSubstitute = NEW random substitute
        do newSubstitute = 'A' + (seed++ % ALPHABET_SIZE);
        while ((newSubstitute == charToSubstitute) || 
            arrayHasTarget(newSubstitute, cipherArray, charNum));
        
        cipherArray[charNum] = newSubstitute;
    }

    // RETRIEVE plain text and cipher text
    cout << "Ciphered text:        ";
    plainTextSize = plainText.size();
    for (int i = 0; i < plainTextSize; i++) {
        char cipher;
        if (isUppercase(plainText[i])) {
            // character = LOOKUP character cipher
            cipher = cipherArray[plainText[i] - 'A'];
        } else cipher = plainText[i];

        cout << cipher;
    }
}
