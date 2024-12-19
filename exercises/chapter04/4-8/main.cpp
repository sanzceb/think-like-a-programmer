#include <iostream>

using std::cout;

struct listNode {
    char character;
    listNode * next;
};
typedef listNode * charCollection;

// remove a section of characters from a string based on
// the starting position and length
void removeChars(charCollection& s1, int pos, int len) {
	if (s1 == NULL) return;
	// SEARCH for node prior to pos
    listNode * prevPtr = s1;
    while (prevPtr != NULL && pos-- > 1) {
        prevPtr = prevPtr->next;
    }
	//if(position not found)
	if (prevPtr == NULL) return;
	// remove each node between pos and len
	while (prevPtr->next != NULL && len-- > 0) {
        listNode * newNext = prevPtr->next->next;
		delete prevPtr->next;
		prevPtr->next = newNext;
    }
}

// Helper functions to run the test
void removeList(charCollection& cc) {
    if (cc == NULL) return;
    if (cc->next == NULL) {delete cc; return;}
    listNode * nextPtr = cc->next;
    while (nextPtr->next != NULL) {
        listNode * newNextPtr = nextPtr->next->next;
        delete nextPtr->next;
        nextPtr->next = newNextPtr;
    }
    delete nextPtr; delete cc;
    cc = NULL;
}

void append(charCollection& cc, char c) {
    //if(list is empty)
    if (cc == NULL) {
        // CREATE the list
        cc = new listNode;
        cc->character = c;
        cc->next = NULL;
    } else { 
        // RETRIEVE last node
        listNode * lastPtr = cc;
        while(lastPtr->next != NULL) {
            lastPtr = lastPtr->next;
        }
        // ADD new node
        listNode * newLastPtr = new listNode;
        newLastPtr->character = c;
        newLastPtr->next = NULL;
        lastPtr->next = newLastPtr;
    }
}

void print(charCollection cc) {
	listNode *loopPtr = cc;
    while (loopPtr != NULL) {
        cout << loopPtr->character;
        loopPtr = loopPtr->next;
    }
}

void removeCharsTester() {
   charCollection cc = NULL;
        
    append(cc, 't');
    append(cc, 'e');
    append(cc, 's');
    append(cc, 't');
	append(cc, 'b');
	append(cc, 'e');
	append(cc, 'd');
	
	removeChars(cc, 5, 2);
	
	print(cc); cout << '\n';

	append(cc, 'e');
	append(cc, 'd');
	
	removeChars(cc, 3, 3);
	
	print(cc);
	
	removeList(cc);
}

int main() {
	removeCharsTester();
}