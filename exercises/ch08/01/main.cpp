#include "hangman_ui.h"

int main() {
   hangmanUI gameWrapper = hangmanUI(hangmanGame("../assets/wordList.txt"));
   gameWrapper.start();
   return 0;
}

