#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;

list<string> readWordFile(char * filename) {
    list<string> wordList;
    // ios::in -> open for reading
    ifstream wordFile(filename, ios::in);
    if (wordFile == NULL) {
        cout << "File open failed. \n";
        return wordList;
    }
    char currentWord[30];
    while (wordFile >> currentWord) {
        //if (word does not include '\')
        if (strchr(currentWord, '\'') == 0) {
            string temp(currentWord);
            wordList.push_back(temp);
        }
    }
    return wordList;
}

int countWordsWithoutLetter(const list<string> & wordList, char letter) {
    list <string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(letter) == string::npos) {
            count++;
        }
        iter++;
    }
    return count;
}

void removeWordsOfWrongLength(list<string> & wordList, int acceptableLength) {
    list <string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->length() != acceptableLength) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void removeWordsWithoutLetter(list<string> & wordList, char requiredLetter) {
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(requiredLetter) == string::npos){
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter) {
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(forbiddenLetter) != string::npos) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

bool numberInPattern(const list <int> & pattern, int number) {
    list<int>::const_iterator iter;
    iter = pattern.begin();
    while (iter != pattern.end()) {
        if (*iter == number) {
            return true;
        }
        iter++;
    }
    return false;
}

bool matchesPattern(string word, char letter, list<int> pattern) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            if (!numberInPattern(pattern, i)) {
                return false;
            }
        } else {
            if (numberInPattern(pattern, i)) {
                return false;
            }
        }
    }
    return true;
}

void mostFreqPatternByLetter(list<string> wordList, char letter,
    list<int> & maxPattern,
    int & maxPatternCount) {
    removeWordsWithoutLetter(wordList, letter);
} 
void displayGuessedLetters(bool letters[26]) {
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++) {
       if (letters[i]) cout << (char)('a' + i) << " ";
    }
    cout << '\n';
}

void displayList(const list<string> & wordList) {
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        cout << iter->c_str() << std::endl;
        iter++;
    }
}

int main() {
    list<string> wordList = readWordFile("wordList.txt");
    const int wordLength = 8;
    bool guessedLetters[26]; 
    for (int i = 0; i < 26; i++) guessedLetters[i] = false;

    cout << "List before: " << '\n';
    displayList(wordList);

    removeWordsOfWrongLength(wordList, wordLength);

    cout << "\nList after: " << '\n';
    displayList(wordList);

    displayGuessedLetters(guessedLetters);

    cout << "words without c: " 
        << countWordsWithoutLetter(wordList, 'c')
        << '\n';
}
