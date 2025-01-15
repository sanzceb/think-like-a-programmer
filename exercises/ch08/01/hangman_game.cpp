#include <iostream>
using std::cout;
#include <string>
using std::string;

#include "hangman_game.h"
#include "word_list.h"


hangmanGame::hangmanGame(string filename) : _wordList(filename) {
    _maxMisses = 9;
    _wordLength = 8;
    _discoveredLetterCount = 0;
    _misses = 0;

    _revealedWord.reserve(_wordLength);
    for (int i = 0; i < _wordLength; i++) {
        _revealedWord.push_back('*');
    }

    for (int i = 0; i < GUESSED_LETTERS_SIZE; i++) {
         _guessedLetters[i] = false;
    }

    _wordList.removeWordsOfWrongLength(_wordLength);
}

void hangmanGame::guessLetter(char letter) {
    _guessedLetters[letter - 'a'] = true;
    int missingCount = _wordList.countWordsWithoutLetter(letter);
    list<int> nextPattern;
    int nextPatternCount;
    _wordList.mostFreqPatternByLetter(letter, nextPattern, nextPatternCount);
    if (missingCount > nextPatternCount) {
        _wordList.removeWordsWithLetter(letter);
        _misses++;
    } else {
        list<int>::iterator iter = nextPattern.begin();
        while (iter != nextPattern.end()) {
            _discoveredLetterCount++;
            _revealedWord[*iter] = letter;
            iter++;
        }
        _wordList.removeWordsWithPattern(letter, nextPattern);
    }
}

void hangmanGame::displayGuessedLetters() {
    cout << "Letters guessed: ";
    for (int i = 0; i < GUESSED_LETTERS_SIZE; i++) {
       if (_guessedLetters[i]) cout << (char)('a' + i) << " ";
    }
    cout << '\n';
}

void hangmanGame::displayRevealedWord() {
        cout << "Word so far: " << _revealedWord << "\n";
}

void hangmanGame::displaySolution() {
    if (_misses == _maxMisses) {
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << _wordList.first().c_str() << "'.\n";
    } else if (_discoveredLetterCount == _wordLength) {
        cout << "Great job. You win. Word was '" << _revealedWord << "'.\n";
    }

}

bool hangmanGame::isRunning() {
    return _discoveredLetterCount < _wordLength && _misses < _maxMisses;
}
