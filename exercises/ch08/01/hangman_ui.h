#ifndef HANGMAN_UI_H
#define HANGMAN_UI_H

#include "hangman_game.h"

class hangmanUI {
public:
    hangmanUI(string filename);
    ~hangmanUI();
    void start();
private:
    hangmanGame * _game;

    void readMisses();
    void readWordLen();
    void displayGuessedLetters();
    void displayRevealedWord();
    void displaySolution();
    void displayAvailableMisses();
};

#endif
