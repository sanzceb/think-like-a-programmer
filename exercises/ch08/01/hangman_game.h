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
    bool setDifficulty(int misses, int wordLength);
private:
    enum state {
        SETUP,
        RUNNING,
        END
    };

    static const int GUESSED_LETTERS_SIZE = 26;

    state _gameState;
    wordList _wordList;
    bool _guessedLetters[GUESSED_LETTERS_SIZE];
    int _maxMisses;
    int _wordLength;
    string _revealedWord;
    int _discoveredLetterCount;
    int _misses;

    void revealLetter(vector<bool> &nextPattern, char letter);
    bool isValidLength(int wordLength);
    bool setMisses(int misses);
    bool setWordLength(int wordLength);
};
#endif