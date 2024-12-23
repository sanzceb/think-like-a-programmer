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
    void append(char chr);
    void concatenate(const charCollection& s2);
    void remove(int pos, int len);
    void output();
private:
    struct charNode {
        char chr;
        charNode * next;
    };
    typedef charNode * charList;

    charList _listHead;

    bool isEmpty() const;
    void deleteList(charList& listPtr);
    charList copiedList(const charList original);
    charNode * lastNode();
    charNode * newNode(char chr);
    charNode * posNode(int pos);
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
    if (isEmpty()) return 0;    
    charNode * searchPtr = posNode(pos);
    // if(node found)
    if (searchPtr != NULL) 
        return searchPtr->chr;
    else 
        return 0;
}

void charCollection::append(char chr) {
    if (isEmpty()) {
        _listHead = newNode(chr);
    } else { 
        lastNode()->next = newNode(chr);
    }
}

void charCollection::concatenate(const charCollection& s2) {
    if (s2.isEmpty()) return;
    // It is more efficient to reach the last node first
    charNode * lastNodePtr = lastNode();
    charNode * loopPtr = s2._listHead;
    do {
        lastNodePtr->next = newNode(loopPtr->chr);
        lastNodePtr = lastNodePtr->next;
        loopPtr = loopPtr->next;
    } while(loopPtr != NULL);
}

void charCollection::remove(int pos, int len) {
	if (isEmpty()) return;
    charNode * prevPtr = posNode(pos - 1);
	//if(position not found)
	if (prevPtr == NULL) return;
	// remove each node between pos and len
	while (prevPtr->next != NULL && len-- > 0) {
        charNode * newNext = prevPtr->next->next;
		delete prevPtr->next;
		prevPtr->next = newNext;
    }
}

void charCollection::output() {
    charNode *loopPtr = _listHead;
    while (loopPtr != NULL) {
        cout << loopPtr->chr;
        loopPtr = loopPtr->next;
    }
}

bool charCollection::isEmpty() const {
    return _listHead == NULL;
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
    charList newList = newNode(original->chr);
    // Traverse and copy
    charNode * loopPtr = original->next;
    charNode * lastPtr = newList;
    while (loopPtr != NULL) {
        lastPtr->next = newNode(loopPtr->chr);
        lastPtr = lastPtr->next;
        loopPtr = loopPtr->next;
    }
    return newList;
}

charCollection::charNode * charCollection::lastNode() {
    charNode * lastPtr = _listHead;
    while(lastPtr->next != NULL) {
        lastPtr = lastPtr->next;
    }
    return lastPtr;
}

charCollection::charNode * charCollection::newNode(char chr) {
    charNode * newNode = new charNode;
    newNode->chr = chr;
    newNode->next = NULL;
    return newNode;
}

charCollection::charNode * charCollection::posNode(int pos) {
    charNode * searchPtr = _listHead;    
    while (searchPtr != NULL && pos-- > 0) {
        searchPtr = searchPtr->next;
    }
    return searchPtr;
}

void appendTester() {
    charCollection cc;
    
    cc.append('t');
    cc.append('e');
    cc.append('s');
    cc.append('t');

    cout << "\nAppend Tester:\n";
    cc.output();
}

void concatenateTester() {
    charCollection cc, cc2;    
    cc.append('t');
    cc.append('e');
    cc.append('s');
    cc.append('t');
    cc2.append('b');
    cc2.append('e');
    cc2.append('d');

    cout << "\nConcatenate Tester:\n";
    cc.concatenate(cc2);
    cc.output();
}

void assignTester() {
   charCollection cc, cc2;   
    cc.append('t');
    cc.append('e');
    cc.append('s');
    cc.append('t');

    cout <<  "Assign Tester\nReferences and values: ";
    cc2 = cc;
    cout << (void*) &cc2 << ' ' << (void*) &cc;

    cout << "\nCopy value: "; cc2.output(); 
    cout << "\nOriginal value: "; cc.output();
    
}

void characterAtTester() {
    charCollection cc;
    int position = 3;
    cc.append('t');
    cc.append('e');
    cc.append('s');
    cc.append('t');
    cout << "\nAccess tester\nCharacter At " << position 
        << ": " <<  cc.characterAt(position);
    cout << "\nOperator[" << position << "]: " << cc[position];
}

void removeTester() {
    charCollection cc, cc2;
    int position = 3;
    cc.append('r');
    cc.append('e');
    cc.append('m');
    cc.append('o');
    cc.append('v');
    cc.append('e');
    cc.append('t');
    cc.append('h');
    cc.append('i');
    cc.append('s');

    cout << "\nRemove Tester\n";
    cc.output();
    cc.remove(6, 4);
    cout << '\n';
    cc.output();
    
    // Try empty list remove
    cc2.remove(0, 1);
}

int main() {
    assignTester();
    removeTester();
    characterAtTester();
    appendTester();
    concatenateTester();
}
