#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include <forward_list>

#include "word_list.h"

class hangmanGame {
public:
    hangmanGame();
    hangmanGame(std::string filename);
    void guessLetter(char letter);

    bool setMisses(int misses);
    bool setWordLen(int wordLen);

    string revealedWord();
    string solution();
    std::forward_list<char> guessedLetters();
    bool isOver();
    bool isRunning();
    int availableMisses();
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
    int _wordLen;
    string _revealedWord;
    int _discoveredLetterCount;
    int _misses;

    void revealLetter(vector<bool> &nextPattern, char letter);
    bool isValidLen(int wordLen);
};

#endif
