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

int listToInt(intList list1) {
    int output = 0;
    listNode * loopPtr = list1;
    while (loopPtr != NULL) {
        output *= 10;
        output += loopPtr->number;
        loopPtr = loopPtr->next;
    }    
    return output;
}

void sum(intList list1, intList list2, intList& output) {
    int op1 = listToInt(list1);
    int op2 = listToInt(list2);
    output = intToList(op1 + op2);
}

// Helper functions
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

int main () {
    intList il = intToList(149);
    intList il2 = intToList(51);
    intList sumList;    
    
    
    sum(il, il2, sumList);
    output(sumList);
    cout << '\n';
    removeList(il);
    removeList(il2);
    removeList(sumList);
    
    sum(NULL, NULL, sumList);
    output(sumList);
    cout << '\n';
    removeList(sumList);
}