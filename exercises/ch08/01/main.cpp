#include <iostream>
using std::cin;
using std::cout;

#include "hangman_game.h"

int main() {
    hangmanGame hangmanGame("../assets/wordList.txt");
    char nextLetter;
    int misses, wordLength;
    bool difficultySet;
    do {
        cout << "Choose the difficulty: "
        << "\nNumber of misses: ";
        cin >> misses;
        cout << "Length of the word: ";
        cin >> wordLength;
        difficultySet = hangmanGame.setDifficulty(misses, wordLength);
    } while (!difficultySet);
    
    hangmanGame.displayRevealedWord();
    while (hangmanGame.isRunning()){
        cout << "Letter to guess: ";
        cin >> nextLetter;
        hangmanGame.guessLetter(nextLetter);
        hangmanGame.displayRevealedWord();
        hangmanGame.displayGuessedLetters();
    }
    hangmanGame.displaySolution();
    return 0;
}
