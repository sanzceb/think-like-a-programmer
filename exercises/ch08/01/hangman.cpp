#include <iostream>
using std::cin;
using std::cout;

#include "hangman_game.h"

int main() {
    hangmanGame hangmanGame("../assets/wordList.txt");
    char nextLetter;
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
