#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;

#include "word_list.h"

void displayGuessedLetters(bool letters[26]) {
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++) {
       if (letters[i]) cout << (char)('a' + i) << " ";
    }
    cout << '\n';
}

int main() {
    wordList wordList("../assets/wordList.txt");
    const int wordLength = 8;
    const int maxMisses = 9;
    int misses = 0;
    int discoveredLetterCount = 0;
    wordList.removeWordsOfWrongLength(wordLength);
    char revealedWord[wordLength + 1] = "********";
    bool guessedLetters[26];
    for (int i = 0; i < 26; i++) guessedLetters[i] = false;
    char nextLetter;
    cout << "Word so far: " << revealedWord << "\n";
    while (discoveredLetterCount < wordLength && misses < maxMisses) {
        cout << "Letter to guess: ";
        cin >> nextLetter;
        guessedLetters[nextLetter - 'a'] = true;
        int missingCount = wordList.countWordsWithoutLetter(nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        wordList.mostFreqPatternByLetter(nextLetter, nextPattern, nextPatternCount);
        if (missingCount > nextPatternCount) {
            wordList.removeWordsWithLetter(nextLetter);
            misses++;
        } else {
            list<int>::iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()) {
                discoveredLetterCount++;
                revealedWord[*iter] = nextLetter;
                iter++;
            }
            wordList.removeWordsWithPattern(nextLetter, nextPattern);
        }
        cout << "Word so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);
    }
    if (misses == maxMisses) {
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << wordList.first().c_str() << "'.\n";
    } else {
        cout << "Great job. You win. Word was '" << revealedWord << "'.\n";
    }
    return 0;
}
