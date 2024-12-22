#include <iostream>

using std::cout;

struct listNode {
    char character;
    listNode * next;
};
typedef listNode * charCollection;

char characterAt(charCollection cc, int p) {
    //if(list is empty)
    if (cc == NULL) return 0;    
    // SEARCH for node at p
    listNode * searchPtr = cc;    
    while (searchPtr != NULL && p-- > 0) {
        searchPtr = searchPtr->next;
    }
    // if(node p found)
    if (searchPtr != NULL) {
        return searchPtr->character;
    } // else p not found  
    return 0;
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

// Helper function to clean up the memory after each test
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

// Test functions
void characterAtTester() {
    charCollection cc = NULL;
    listNode * node1 = new listNode;
    node1->character = 't';
    listNode * node2 = new listNode;
    node2->character = 'e';
    listNode * node3 = new listNode;
    node3->character = 's';
    listNode * node4 = new listNode;
    node4->character = 't';

    // Link the nodes
    cc = node1;
    node1->next = node2;    
    node2->next = node3;    
    node3->next = node4;
    node4->next = NULL;
    node1 = node2 = node3 = node4 = NULL;    

    for (int i = 0; i <= 4; i++) {
        cout << "\nChar " << i << ':' << characterAt(cc, i);
    }

    removeList(cc);
    cout << '\n';
    
}

void appendTester() {
    charCollection cc = NULL;
        
    append(cc, 't');
    append(cc, 'e');
    append(cc, 's');
    append(cc, 't');
    append(cc, '!');
    
    for (int i = 0; i <= 5; i++) {
        cout << "\nChar " << i << ':' << characterAt(cc, i);
    }

    cout << '\n';
    removeList(cc);
}
int main() {
    characterAtTester();
    appendTester();
}