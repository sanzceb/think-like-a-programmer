#include <iostream>
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <cstring>

#include "word_list.h"

static bool numberInPattern(const list <int> & pattern, int number) {
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

static bool matchesPattern(string word, char letter, const list<int> & pattern) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            if (!numberInPattern(pattern, i)) {
                return false;
            }
        }
        else {
            if (numberInPattern(pattern, i)) {
                return false;
            }
        }
    }
    return true;
}

static list<string> readWordFile(string filename) {
    list<string> wordList;
    // ios::in -> open for reading
    ifstream wordFile(filename, ios::in);
    // Modern C++ does not do implicit conversion to void *
    // but it does conversion to bool
    //if(wordFile == NULL) is not allowed in strict compilers
    if (!wordFile) {
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

static void removeWordsWithoutLetter(list<string> & wordList, char letter) {
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(letter) == string::npos){
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

wordList::wordList(string filename) {
    _wordList = readWordFile(filename);
}

int wordList::countWordsWithoutLetter(char letter) {
    list <string>::const_iterator iter;
    int count = 0;
    iter = _wordList.begin();
    while (iter != _wordList.end()) {
        if (iter->find(letter) == string::npos) {
            count++;
        }
        iter++;
    }
    return count; 
}

void wordList::removeWordsWithLetter(char letter) {
    list<string>::iterator iter;
    iter = _wordList.begin();
    while (iter != _wordList.end()) {
        if (iter->find(letter) != string::npos) {
            iter = _wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void wordList::removeWordsOfWrongLength(int acceptableLength) {
    list<string>::iterator iter;
    iter = _wordList.begin();
    while (iter != _wordList.end()) {
        if (iter->length() != acceptableLength) {
            iter = _wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void wordList::mostFreqPatternByLetter(char letter, list<int> &maxPattern,
    int &maxPatternCount) {
    maxPatternCount = 0;
    list<string> wordListCopy = _wordList;
    removeWordsWithoutLetter(wordListCopy, letter);
    list<string>::iterator iter;
    while (wordListCopy.size() > 0) {
        iter = wordListCopy.begin();
        list<int> currentPattern;
        for (int i = 0; i < iter->length(); i++) {
            if ((*iter)[i] == letter) {
                currentPattern.push_back(i);
            }
        }
        int currentPatternCount = 1;
        iter = wordListCopy.erase(iter);
        while (iter != wordListCopy.end()) {
            if (matchesPattern(*iter, letter, currentPattern)) {
                currentPatternCount++;
                iter = wordListCopy.erase(iter);
            } else {
                iter++;
            }
        }
        if (currentPatternCount > maxPatternCount) {
            maxPatternCount = currentPatternCount;
            maxPattern = currentPattern;
        }
        currentPattern.clear();
    }
}

void wordList::removeWordsWithPattern(char letter, list<int> pattern) {
    list<string>::iterator iter;
    iter = _wordList.begin();
    while(iter != _wordList.end()) {
        if (!matchesPattern(*iter, letter, pattern)) {
            iter = _wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void wordList::displayWordList() {
    list<string>::const_iterator iter;
    iter = _wordList.begin();
    while (iter != _wordList.end()) {
        cout << iter->c_str() << std::endl;
        iter++;
    }
}

string wordList::first() {
    return *_wordList.begin();
}
