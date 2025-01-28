#include <iostream>
using std::streamsize;
using std::cout;
using std::cin;
#include <string>
using std::string;
#include <forward_list>
using std::forward_list;
#include <limits>
using std::numeric_limits;

#include "hangman_ui.h"

hangmanUI::hangmanUI(hangmanGame game) {
    _game = game;
}

void hangmanUI::displayGuessedLetters() {
    forward_list<char>::const_iterator iter;
    forward_list<char> gl = _game.guessedLetters();

    cout << "\nLetters guessed:";
    iter = gl.begin();
    while (iter != gl.end()) {
        cout << " " << *iter;
        iter++;
    }
}

void hangmanUI::displayRevealedWord() {
    cout << "\nWord so far: " << _game.revealedWord();
}

void hangmanUI::displaySolution() {
    if (_game.isOver()) {
        cout << "\nSorry, you lost. The word I was thinking of was '";
    } else if (!_game.isRunning()) {
        cout << "\nGreat job. You win. Word was '";
    }
    cout << _game.solution().c_str() << "'.";
}

void hangmanUI::displayAvailableMisses() {
    if (_game.isRunning()) {
        cout << "\nMisses available: " << _game.availableMisses();
    }
}

void hangmanUI::readMisses() {
    int misses;
    bool missesSet;
    streamsize maxSize = numeric_limits<streamsize>::max();
    do {
        cout << "\nNumber of misses: ";
        cin >> misses;
        if (cin.fail()) {
            cin.clear();
            missesSet = false;
            cout << "Bad input!";
        } else {
            missesSet = _game.setMisses(misses);
            if (!missesSet) {
                cout << "Number of tries is invalid.";
            }
        }
        cin.ignore(maxSize, '\n');
    } while (!missesSet);
}

void hangmanUI::readWordLen() {
    int wordLen;
    bool lenSet;
    streamsize maxSize = numeric_limits<streamsize>::max();
    do {
        cout << "\nLength of the word: ";
        cin >> wordLen;
        if (cin.fail()) {
            cin.clear(); // Clear status
            lenSet = false;
            cout << "Bad input!";
        } else {
            lenSet = _game.setWordLen(wordLen);
            if (!lenSet) {
                cout << "I do not know words of such size!";
            }
        }
        cin.ignore(maxSize, '\n'); //Clear bad input
    } while (!lenSet);
}

void hangmanUI::start() {
    char nextLetter;
    int misses, wordLength;
    cout << "Choose the difficulty: ";
    readMisses();
    readWordLen();
    while (_game.isRunning()){
        displayRevealedWord();
        displayAvailableMisses();
        displayGuessedLetters();
        cout << "\n\nLetter to guess: ";
        cin >> nextLetter;
        cin.ignore();
        _game.guessLetter(nextLetter);
    }
    displaySolution();
}

