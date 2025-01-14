#include<string>
using std::string;
#include <list>
using std::list;

#ifndef WORD_LIST_H
#define WORD_LIST_H
class wordList {
public:
    wordList(string filename);

    int countWordsWithoutLetter(char letter);
    void removeWordsWithLetter(char letter);
    void removeWordsOfWrongLength(int acceptableLength);
    void removeWordsWithPattern(char nextLetter, list<int> nextPattern);
    void mostFreqPatternByLetter(char letter, list<int> & maxPattern,
    int & maxPatternCount);
    void displayWordList();
    string first();
private : 
    list<string> _wordList;
};
#endif