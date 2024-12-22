#include <iostream>

using std::cout;

class charCollection {
public:
    charCollection();
    charCollection(const charCollection& original);
    ~charCollection();
    charCollection& operator=(const charCollection& rhs);
    char operator[](int pos);
    char characterAt(int pos);
    void append(char c);
    void concatenate(const charCollection& s2);
    void output();    
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

charCollection &charCollection::operator=(const charCollection& rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
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

void charCollection::concatenate(const charCollection& s2) {
    if (s2._listHead == NULL) return;
    // It is more efficient to reach the last node first
    charNode * lastNodePtr = NULL;
    charNode * loopPtr = _listHead;
    while (loopPtr != NULL) {
        lastNodePtr = loopPtr;
        loopPtr = loopPtr->next;
    }
    loopPtr = s2._listHead;
    do { // TRAVERSE s2 and COPY each node
        append(loopPtr->character);
        loopPtr = loopPtr->next;
        lastNodePtr = lastNodePtr->next;
    } while(loopPtr != NULL);
}

void charCollection::output() {
    charNode *loopPtr = _listHead;
    while (loopPtr != NULL) {
        cout << loopPtr->character;
        loopPtr = loopPtr->next;
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

charCollection::charList charCollection::copiedList(const charList original) {
    if (original == NULL) return NULL;
    charList newList = new charNode;
    newList->character = original->character;
    
    // Traverse and copy
    charNode * loopPtr = original->next;
    charNode * lastPtr = newList;
    while (loopPtr != NULL) {
        lastPtr->next = new charNode;
        lastPtr = lastPtr->next;
        lastPtr->character = loopPtr->character;
        loopPtr = loopPtr->next;
    }
    // It avoids storing bad references
    lastPtr->next = NULL;
    return newList;
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
