#include <iostream>

using std::cout;

struct listNode {
    int studentNum;
    listNode * next;
};

typedef listNode * studentCollection;

void removeRecord(studentCollection& sc, int studentNum) {
    if (sc != NULL) {
        //if(record found in root)
        if (sc->studentNum == studentNum) {
            studentCollection newNext = sc->next;
            delete sc;
            sc = newNext;
        } else {
            // LIST SEARCH record
            listNode  *prevPtr = sc, *nextPtr = sc->next;
            while (nextPtr != NULL 
                && nextPtr->studentNum != studentNum) {
                    prevPtr = nextPtr;
                    nextPtr = nextPtr->next;
            }
            //if(record found in next)
            if (nextPtr != NULL) {
                listNode * newNext = nextPtr->next;
                delete nextPtr;
                prevPtr->next = newNext;
            }
        }            
    }
 }

void printRecords(studentCollection sc) {
    listNode * scPtr = sc;
    while(scPtr != NULL) {
        cout << '\n' << scPtr->studentNum;
        scPtr = scPtr->next;
    }
}

void removeRecordTester() {
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1001;
    listNode * node2 = new listNode;
    node2->studentNum = 1012;
    listNode * node3 = new listNode;
    node3->studentNum = 1076;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = NULL, node2 = NULL, node3 = NULL;

    cout << "Student List:";
    printRecords(sc);
    cout << "\nRemoving student 1012";
    removeRecord(sc, 1012);

    cout << "\n\nNew Student List";
    printRecords(sc);

    cout << "\nRemoving student 1076";
    removeRecord(sc, 1076);

    cout << "\n\nNew Student List";
    printRecords(sc);
    
    cout << "\nRemoving student 1001";
    removeRecord(sc, 1001);
    cout << "\n\nNew Student List:";
    printRecords(sc); cout << '\n';
}

int main() {
    removeRecordTester();
}