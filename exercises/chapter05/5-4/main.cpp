#include <iostream>

using std::cout;

class charCollection {
public:
    charCollection();
    charCollection(const charCollection& original);
    ~charCollection();
    char operator[](int pos);
    char characterAt(int pos);
    void append(char c); 
private:
    struct charNode {
        char character;
        charNode * next;
    };
    typedef charNode * charList;

    charList _listHead;

    void deleteList(charList& listPtr);
    charList copiedList(const charList original);
};

charCollection::charCollection() {
    _listHead = NULL; // NULL signifies an empty list
}

charCollection::~charCollection() {
    deleteList(_listHead);
}

char charCollection::operator[](int pos) {
    return characterAt(pos);
}

char charCollection::characterAt(int pos) {
    if (_listHead == NULL) return 0;    
    // SEARCH for node at pos
    charNode * searchPtr = _listHead;    
    while (searchPtr != NULL && pos-- > 0) {
        searchPtr = searchPtr->next;
    }
    // if(node found)
    if (searchPtr != NULL) {
        return searchPtr->character;
    }
    return 0;
}

void charCollection::append(char c) {
    if (_listHead == NULL) {
        _listHead = new charNode;
        _listHead->character = c;
        _listHead->next = NULL;
    } else { 
        // Retrieve the last node
        // then add a new node next to it
        charNode * lastPtr = _listHead;
        while(lastPtr->next != NULL) {
            lastPtr = lastPtr->next;
        }
        charNode * newLastPtr = new charNode;
        newLastPtr->character = c;
        newLastPtr->next = NULL;
        lastPtr->next = newLastPtr;
    }
}

void charCollection::deleteList(charList &listPtr) {
    while (listPtr != NULL) {
        // keep the list always linked
        charNode * tmpPtr = listPtr->next;
        delete listPtr;
        listPtr = tmpPtr;
    }
}

int main() {
    charCollection cc;
    int position = 3;
    cc.append('t');
    cc.append('e');
    cc.append('s');
    cc.append('t');

    cout << "Character At " << position 
        << ": " <<  cc.characterAt(position);
    cout << "\nOperator[" << position << "]: " << cc[position];
}
