#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <forward_list>
using std::forward_list;

#include "hangman_game.h"
#include "word_list.h"

hangmanGame::hangmanGame() : _wordList("") {
    init();
}

hangmanGame::hangmanGame(string filename) : _wordList(filename) {
    init();
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
    updateState();
}

forward_list<char> hangmanGame::guessedLetters() {
    forward_list<char> guessedLetters;
    for (int i = 0; i < GUESSED_LETTERS_SIZE; i++) {
       if (_guessedLetters[i]) {
	  guessedLetters.push_front((char)('a' + i));
       }
    }
    return guessedLetters;
}

string hangmanGame::revealedWord() {
    return _revealedWord;
}

string hangmanGame::solution() {
    if (isOver()) {
	return _wordList.first();
    } else {
	return _revealedWord;
    }
}

bool hangmanGame::isOver() {
    return _misses > _maxMisses;
}

bool hangmanGame::isRunning() {
    return _discoveredLetterCount < _wordLen && _misses <= _maxMisses;
}

bool hangmanGame::isValidLen(int wordLen) {
    pair <int, int> sizeRange = _wordList.sizeRange();
    return sizeRange.first <= wordLen &&
        sizeRange.second >= wordLen;
}

bool hangmanGame::setMisses(int misses) {
    if (_gameState != MISSES_SETUP) return false;
    if (misses < 0) return false;
    _maxMisses = misses;
    updateState();
    return true;
}

bool hangmanGame::setWordLen(int wordLen) {
    if (_gameState != WORD_LEN_SETUP) {
        return false;
    }
    if (!isValidLen(wordLen)) {
        return false;
    } 
    _wordLen = wordLen;
    _revealedWord.reserve(_wordLen);
    for (int i = 0; i < _wordLen; i++) {
        _revealedWord.push_back('*');
    }
    _wordList.removeWordsOfWrongLength(_wordLen);
    updateState();
    return true;
}

int hangmanGame::availableMisses() {
    return _maxMisses - _misses;
}

void hangmanGame::updateState() {
    switch (_gameState) {
        case MISSES_SETUP:
            _gameState = WORD_LEN_SETUP;
            break;
        case WORD_LEN_SETUP:
            _gameState = RUNNING;
            break;
        case RUNNING:
            if (!isRunning())
                _gameState = END;
            break;
        case END:
            break;
    }
}

void hangmanGame::resetGame() {
    init();
}

void hangmanGame::init() {
    _gameState = MISSES_SETUP;
    _discoveredLetterCount = 0;
    _misses = 0;
    for (int i = 0; i < GUESSED_LETTERS_SIZE; i++) {
         _guessedLetters[i] = false;
    }
}
