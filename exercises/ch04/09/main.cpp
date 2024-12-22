#include <iostream>

using std::cout;

struct listNode {
    int number;
    listNode * next;
};

typedef listNode * intList;

void addInt(intList& intList, int number) {
    listNode * newInt = new listNode;
    newInt->number = number;
    newInt->next = intList;
    intList = newInt;
}

intList intToList(int number) {
    // The list always has at least one digit
    // The modulo operator extracts the digit
    // and the division reduces the number by
    // shifting the digits to the right.
    intList il = NULL;
    do {
        int digit = number % 10;
        addInt(il, digit);
        number /= 10;
    } while (number > 0);
    return il;
}

// Helper functions to run the test
void output(intList il) {
	listNode *loopPtr = il;
    while (loopPtr != NULL) {
        cout << loopPtr->number;
        loopPtr = loopPtr->next;
    }
}

void removeList(intList& il) {
    if (il == NULL) return;
    if (il->next == NULL) {delete il; return;}
    listNode * nextPtr = il->next;
    while (nextPtr->next != NULL) {
        listNode * newNextPtr = nextPtr->next->next;
        delete nextPtr->next;
        nextPtr->next = newNextPtr;
    }
    delete nextPtr; delete il;
    il = NULL;
}

int main() {
    intList intList = intToList(58393);
    output(intList);
    cout << '\n';
    removeList(intList);
    
    intList = intToList(149);
    output(intList);
    cout << '\n';
    removeList(intList);

    intList = intToList(0);
    output(intList);
    cout << '\n';
    removeList(intList);

    return 0;
}