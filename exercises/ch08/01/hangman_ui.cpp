#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
#include <forward_list>
using std::forward_list;

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
    cout << "\nWord so far: " << _game.revealedWord() << "\n";
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
    cout << "\nMisses available: " << _game.availableMisses();
}

void hangmanUI::readMisses() {
    int misses;
    bool missesSet;
    do {
	cout << "\nNumber of misses: ";
	cin >> misses;
	cin.ignore();
	missesSet = _game.setMisses(misses);
	if (!missesSet) {
	    cout << "Number of tries is invalid.\n";
	}
    } while (!missesSet);
}

void hangmanUI::readWordLen() {
    int wordLen;
    bool lenSet;
    do {
        cout << "\nLength of the word: ";
        cin >> wordLen;
	cin.ignore();
	lenSet = _game.setWordLen(wordLen);
	if (!lenSet) {
            cout << "I do not know words of such size!\n";
	}
    } while (!lenSet);
}

void hangmanUI::start() {
    char nextLetter;
    int misses, wordLength;
    cout << "Choose the difficulty: ";
    readMisses();
    readWordLen();
    displayRevealedWord();
    while (_game.isRunning()){
        cout << "\nLetter to guess: ";
        cin >> nextLetter;
        cin.ignore();
        _game.guessLetter(nextLetter);
        displayRevealedWord();
        displayGuessedLetters();
        displayAvailableMisses();
    }
    displaySolution();
}

