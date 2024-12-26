#include <iostream>
#include <cassert>

using std::cout;

struct listNode {
    char data;
    listNode * next;
};

typedef listNode * listPtr;

bool hasOddParity(listPtr binaryStr) {
    if (binaryStr->next == NULL)
        return binaryStr->data == '1';
    bool subParity = hasOddParity(binaryStr->next);
    if (binaryStr->data == '1') return !subParity;
    else return subParity;
}

// AI generated test
void testHasOddParity() {
    // Test 1: 1010101 (4 ones - should return false)
    listPtr test1 = new listNode;
    test1->data = '1';
    test1->next = new listNode;
    test1->next->data = '0';
    test1->next->next = new listNode;
    test1->next->next->data = '1';
    test1->next->next->next = new listNode;
    test1->next->next->next->data = '0';
    test1->next->next->next->next = new listNode;
    test1->next->next->next->next->data = '1';
    test1->next->next->next->next->next = new listNode;
    test1->next->next->next->next->next->data = '0';
    test1->next->next->next->next->next->next = new listNode;
    test1->next->next->next->next->next->next->data = '1';
    test1->next->next->next->next->next->next->next = NULL;
    cout << "\nTest 1: " << (hasOddParity(test1) ? 
    "Has odd parity" : "Has even parity");
    assert(hasOddParity(test1) == false);

    // Test 2: 11110000 (4 ones - should return false)
    listPtr test2 = new listNode;
    test2->data = '1';
    test2->next = new listNode;
    test2->next->data = '1';
    test2->next->next = new listNode;
    test2->next->next->data = '1';
    test2->next->next->next = new listNode;
    test2->next->next->next->data = '1';
    test2->next->next->next->next = new listNode;
    test2->next->next->next->next->data = '0';
    test2->next->next->next->next->next = new listNode;
    test2->next->next->next->next->next->data = '0';
    test2->next->next->next->next->next->next = new listNode;
    test2->next->next->next->next->next->next->data = '0';
    test2->next->next->next->next->next->next->next = new listNode;
    test2->next->next->next->next->next->next->next->data = '0';
    test2->next->next->next->next->next->next->next->next = NULL;
    cout << "\nTest 2: " << (hasOddParity(test2) ? 
    "Has odd parity" : "Has even parity");
    assert(hasOddParity(test2) == false);

    // Test 3: 0010000 (1 one - should return true)
    listPtr test3 = new listNode;
    test3->data = '0';
    test3->next = new listNode;
    test3->next->data = '0';
    test3->next->next = new listNode;
    test3->next->next->data = '1';
    test3->next->next->next = new listNode;
    test3->next->next->next->data = '0';
    test3->next->next->next->next = new listNode;
    test3->next->next->next->next->data = '0';
    test3->next->next->next->next->next = new listNode;
    test3->next->next->next->next->next->data = '0';
    test3->next->next->next->next->next->next = new listNode;
    test3->next->next->next->next->next->next->data = '0';
    test3->next->next->next->next->next->next->next = NULL;
    cout << "\nTest 3: " << (hasOddParity(test3) ? 
    "Has odd parity" : "Has even parity");
    assert(hasOddParity(test3) == true);

    // Test 4: 0000000 (0 ones - should return false)
    listPtr test4 = new listNode;
    test4->data = '0';
    test4->next = new listNode;
    test4->next->data = '0';
    test4->next->next = new listNode;
    test4->next->next->data = '0';
    test4->next->next->next = new listNode;
    test4->next->next->next->data = '0';
    test4->next->next->next->next = new listNode;
    test4->next->next->next->next->data = '0';
    test4->next->next->next->next->next = new listNode;
    test4->next->next->next->next->next->data = '0';
    test4->next->next->next->next->next->next = new listNode;
    test4->next->next->next->next->next->next->data = '0';
    test4->next->next->next->next->next->next->next = NULL;
    cout << "\nTest 4: " << (hasOddParity(test4) ? 
    "Has odd parity" : "Has even parity");
    assert(hasOddParity(test4) == false);

    // Test 5: 1111111 (7 ones - should return true)
    listPtr test5 = new listNode;
    test5->data = '1';
    test5->next = new listNode;
    test5->next->data = '1';
    test5->next->next = new listNode;
    test5->next->next->data = '1';
    test5->next->next->next = new listNode;
    test5->next->next->next->data = '1';
    test5->next->next->next->next = new listNode;
    test5->next->next->next->next->data = '1';
    test5->next->next->next->next->next = new listNode;
    test5->next->next->next->next->next->data = '1';
    test5->next->next->next->next->next->next = new listNode;
    test5->next->next->next->next->next->next->data = '1';
    test5->next->next->next->next->next->next->next = NULL;
    cout << "\nTest 5: " << (hasOddParity(test5) ? 
    "Has odd parity" : "Has even parity");
    assert(hasOddParity(test5) == true);

    cout << "\n\nAll test cases passed successfully!\n";

    // Clean up memory
    delete test1;
    delete test2;
    delete test3;
    delete test4;
    delete test5;
}

int main() {
    testHasOddParity();
}