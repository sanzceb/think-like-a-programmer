#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H
#include <list>

#include "word_list.h"

class hangmanGame {
public:
    hangmanGame(std::string filename);
    void guessLetter(char letter);
    void displayGuessedLetters();
    void displayRevealedWord();
    void displaySolution();
    bool isRunning();
private:
    static const int GUESSED_LETTERS_SIZE = 26;

    wordList _wordList;
    bool _guessedLetters[GUESSED_LETTERS_SIZE];
    int _maxMisses;
    int _wordLength;
    string _revealedWord;
    int _discoveredLetterCount;
    int _misses;
};
#endif