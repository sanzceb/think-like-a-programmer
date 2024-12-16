#include <iostream>

using std::cout;

struct listNode {
    char character;
    listNode * next;
};
typedef listNode * charCollection;

//Retrieve the last node of the char collection
listNode * lastNode(charCollection cc) {
    listNode * lastPtr = cc;
    while(lastPtr->next != NULL) {
        lastPtr = lastPtr->next;
    }
    return lastPtr;
}

// Creates a new node with payload c and 
// adds it to the end of the char collection
void append(charCollection& cc, char c) {
    //if(list is empty)
    if (cc == NULL) {
        // CREATE the list
        cc = new listNode;
        cc->character = c;
        cc->next = NULL;
    } else { 
        listNode * lastPtr = lastNode(cc);
        // ADD new node
        listNode * newLastPtr = new listNode;
        newLastPtr->character = c;
        newLastPtr->next = NULL;
        lastPtr->next = newLastPtr;
    }
}

// Creates a copy of each node in s2 and append them
// to the end of s1
void concatenate(charCollection& s1, charCollection s2) {
    if (s2 == NULL) return;
    // It is more efficient to reach s1's last node first
    listNode * last_s1Ptr = lastNode(s1);    
    listNode * loopPtr = s2;
    do { // TRAVERSE s2 and COPY each node
        append(last_s1Ptr, loopPtr->character);
        loopPtr = loopPtr->next;
        last_s1Ptr = last_s1Ptr->next;
    } while(loopPtr != NULL);
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
void concatenateTester() {
    charCollection cc = NULL, cc2 = NULL;
    
    append(cc, 't');
    append(cc, 'e');
    append(cc, 's');
    append(cc, 't');
    
    append(cc2, 'b');
    append(cc2, 'e');
    append(cc2, 'd');
    
    concatenate(cc, cc2);
    
    listNode *loopPtr = cc;
    while (loopPtr != NULL) {
        cout << loopPtr->character;
        loopPtr = loopPtr->next;
    }
    cout << '\n';
    
    
    removeList(cc);
    removeList(cc2);

}

int main() {
    concatenateTester();
}