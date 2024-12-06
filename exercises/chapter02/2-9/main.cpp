#include <iostream>

using std::cin;
using std::cout;

int is_vowel(char character) {
    if (character >= 'A' && character <= 'Z') character += 32;
    switch (character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return 1;
        default: return 0;
    }
}

int is_punctuation(char character) {
    switch (character) {
    case '!':
    case '?':
    case ',':
    case '.':
    case ' ':
    case ';':
    case '"':
    case '\'':
    case '\n': return 1;
    default: return 0;
    }
}

int main() {
    enum modeType {LETTER, PUNCTUATION};
    modeType mode = PUNCTUATION;
    char character;
    int wordCount = 0, maxWordLen = 0, currWordLen = 0,
        maxVowelCount = 0, currVowelCount = 0;

    cout << "Enter a line of text: ";
    do {
        character = cin.get();
        switch (mode) {
        case LETTER:
            if (1 == is_punctuation(character)) {
                if (currWordLen > maxWordLen) maxWordLen = currWordLen; 
                if (currVowelCount > maxVowelCount) {
                    maxVowelCount = currVowelCount;
                }
                mode = PUNCTUATION;
            } else {
                if (1 == is_vowel(character)) ++currVowelCount;
                ++currWordLen;
            }
            break;
        case PUNCTUATION:
            if (0 == is_punctuation(character)) {
                ++wordCount;
                currWordLen = 1;
                if (1 == is_vowel(character)) currVowelCount = 1;
                else currVowelCount = 0;
                mode = LETTER;
            }
            break;
        }
    } while (character != 10);

    cout << "The total number of words is: "
        << wordCount << ".\n";
    cout << "The greatest word has "
        << maxWordLen << ".\n";
    cout << "The greatest number of vowels in a word is: "
        << maxVowelCount << ".\n";
}