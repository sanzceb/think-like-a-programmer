#include <iostream>
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <cstring>
#include <vector>
using std::vector;

#include "word_list.h"

static bool matchesPattern(string word, char letter,
    const vector<bool> & pattern) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            if (!pattern[i]) {
                return false;
            }
        } else if (pattern[i]) {
            return false;
        }
    }
    return true;
}

static void readWordFile(string filename, list<string> & wordList, 
    pair<int, int> & sizeRange) {
    // ios::in -> open for reading
    ifstream wordFile(filename, ios::in);
    // Modern C++ does not do implicit conversion to void *
    // but it does conversion to bool
    //if(wordFile == NULL) is not allowed in strict compilers
    if (!wordFile) {
        cout << "File open failed. \n";
        return;
    }
    char currentWord[30];
    int minSize = INT_MAX, maxSize = -1;
    while (wordFile >> currentWord) {
        //if (word does not include '\')
        if (strchr(currentWord, '\'') == 0) {
            string temp(currentWord);
            int tempSize = temp.size();
            wordList.push_back(temp);
            if (tempSize < minSize) {
                minSize = tempSize; 
            }
            if (tempSize > maxSize) {
                maxSize = tempSize;
            }
        }
    }
    sizeRange = std::make_pair(minSize, maxSize);
}


wordList::wordList(string filename) {
    readWordFile(filename, _wordList, _sizeRange);
}

wordList::wordList(const wordList & original) {
    _wordList = original._wordList;
    _sizeRange = original._sizeRange;
}

pair<int, int> wordList::sizeRange() {
    return _sizeRange;
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

void wordList::removeWordsWithoutLetter(char letter) {
    list<string>::iterator iter;
    iter = _wordList.begin();
    while (iter != _wordList.end()) {
        if (iter->find(letter) == string::npos){
            iter = _wordList.erase(iter);
        } else {
            iter++;
        }
    }
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

void wordList::mostFreqPatternByLetter(char letter, vector<bool> &maxPattern,
    int &maxPatternCount) {
    maxPatternCount = 0;
    wordList wordListCopy(*this);
    wordListCopy.removeWordsWithoutLetter(letter);
    list<string> _wordListCopy = wordListCopy._wordList;
    list<string>::iterator iter;
    while (_wordListCopy.size() > 0) {
        iter = _wordListCopy.begin();
        vector<bool> currentPattern;
        currentPattern.reserve(iter->length());
        for (int i = 0; i < iter->length(); i++) {
            currentPattern.push_back((*iter)[i] == letter);
        }
        int currentPatternCount = 1;
        iter = _wordListCopy.erase(iter);
        while (iter != _wordListCopy.end()) {
            if (matchesPattern(*iter, letter, currentPattern)) {
                currentPatternCount++;
                iter = _wordListCopy.erase(iter);
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

void wordList::removeWordsWithPattern(char letter, vector<bool> pattern) {
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
