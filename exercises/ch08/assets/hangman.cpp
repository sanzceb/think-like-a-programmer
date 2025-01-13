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

void displayList(const list<string> & wordList) {
    for (list<string>::const_iterator it = wordList.begin();
         it != wordList.end();
         it++) {
        cout << it->c_str() << std::endl;
    }
}

int main() {
    list<string> wordList = readWordFile("wordList.txt");
    const int wordLength = 8;

    cout << "List before: " << '\n';
    displayList(wordList);
    removeWordsOfWrongLength(wordList, wordLength);
    cout << "\nList after: " << '\n';
    displayList(wordList);
}
