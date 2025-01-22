#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "hangman_game.h"
#include "word_list.h"


hangmanGame::hangmanGame(string filename) : _wordList(filename) {
    _gameState = SETUP;
    _discoveredLetterCount = 0;
    _misses = 0;
    for (int i = 0; i < GUESSED_LETTERS_SIZE; i++) {
         _guessedLetters[i] = false;
    }
}

void hangmanGame::revealLetter(vector<bool> &nextPattern, char letter) {
    for (int i = 0; i < nextPattern.size(); i++) {
        if (nextPattern[i]){
            _discoveredLetterCount++;
            _revealedWord[i] = letter;
        }
    }
}

void hangmanGame::guessLetter(char letter) {
    if (_gameState != RUNNING) return;
    _guessedLetters[letter - 'a'] = true;
    int missingCount = _wordList.countWordsWithoutLetter(letter);
    vector<bool> nextPattern;
    int nextPatternCount;
    _wordList.mostFreqPatternByLetter(letter, nextPattern, nextPatternCount);
    if (missingCount > nextPatternCount) {
        _wordList.removeWordsWithLetter(letter);
        _misses++;
    } else {
        revealLetter(nextPattern, letter);
        _wordList.removeWordsWithPattern(letter, nextPattern);
    }
    if (isRunning() == false) {
        _gameState = END;
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
    if (_misses > _maxMisses) {
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << _wordList.first().c_str() << "'.\n";
    } else if (_discoveredLetterCount == _wordLength) {
        cout << "Great job. You win. Word was '" << _revealedWord << "'.\n";
    }

}

bool hangmanGame::isRunning() {
    return _discoveredLetterCount < _wordLength && _misses < _maxMisses;
}

bool hangmanGame::isValidLength(int wordLength) {
    pair <int, int> sizeRange = _wordList.sizeRange();
    return sizeRange.first <= wordLength &&
        sizeRange.second >= wordLength;
}

bool hangmanGame::setMisses(int misses) {
    if (misses < 0) return false;
    _maxMisses = misses;
    return true;
}

bool hangmanGame::setWordLength(int wordLength) {
    if (!isValidLength(wordLength)) {
        return false;
    } 
    _wordLength = wordLength;
    _revealedWord.reserve(_wordLength);
    for (int i = 0; i < _wordLength; i++) {
        _revealedWord.push_back('*');
    }
    _wordList.removeWordsOfWrongLength(_wordLength);
    return true;
}

bool hangmanGame::setDifficulty(int misses, int wordLength) {
    bool inputValid = true;
    if (!setMisses(misses)) {
        cout << "Number of tries is invalid.\n";
        inputValid =  false;
    } 
    if (!setWordLength(wordLength)) {
        cout << "I do not know words of such size!\n";
        inputValid = false;
    }
    if (!inputValid) {
        cout << "Please try again!\n";
        return false;
    }
    _gameState = RUNNING;
    return true;
}

int hangmanGame::availableMisses() {
    return _maxMisses - _misses;
}

