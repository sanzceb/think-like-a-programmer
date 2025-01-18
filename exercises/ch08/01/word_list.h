#include<string>
using std::string;
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <tuple>
using std::pair;

#ifndef WORD_LIST_H
#define WORD_LIST_H
class wordList {
public:
    wordList(string filename);
    wordList(const wordList &);
    //Returns a tuple with the minimum and maximum word size
    pair<int, int> sizeRange();

    int countWordsWithoutLetter(char letter);
    void removeWordsWithLetter(char letter);
    void removeWordsWithoutLetter(char letter);
    void removeWordsOfWrongLength(int acceptableLength);
    void removeWordsWithPattern(char nextLetter, vector<bool> nextPattern);
    void mostFreqPatternByLetter(char letter, vector<bool> & maxPattern,
    int & maxPatternCount);
    void displayWordList();
    string first();
private : 
    list<string> _wordList;
    pair <int, int> _sizeRange;
};
#endif