#include <iostream>
#include <cassert>

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
    if (pos <= -len) return;
    removeChars(s1->next, pos - 1,  len);
    if (pos <= 0) {
        listNode * tmp = s1->next;
        delete s1;
        s1 = tmp;
    }
}

void removeCharsTester() {
    // Test Case 1: Remove characters from middle of list
    charCollection test1 = new listNode;
    test1->character = 'H';
    test1->next = new listNode;
    test1->next->character = 'e';
    test1->next->next = new listNode;
    test1->next->next->character = 'l';
    test1->next->next->next = new listNode;
    test1->next->next->next->character = 'l';
    test1->next->next->next->next = new listNode;
    test1->next->next->next->next->character = 'o';
    test1->next->next->next->next->next = NULL;
    removeChars(test1, 1, 2);  // Should become "Hlo"
    assert(test1->character == 'H');
    assert(test1->next->character == 'l');
    assert(test1->next->next->character == 'o');
    assert(test1->next->next->next == NULL);
    cout << "\nTest Case 1 Passed: Remove from middle";

    // Test Case 2: Remove characters from start of list
    charCollection test2 = new listNode;
    test2->character = 'W';
    test2->next = new listNode;
    test2->next->character = 'o';
    test2->next->next = new listNode;
    test2->next->next->character = 'r';
    test2->next->next->next = new listNode;
    test2->next->next->next->character = 'l';
    test2->next->next->next->next = new listNode;
    test2->next->next->next->next->character = 'd';
    test2->next->next->next->next->next = NULL;
    removeChars(test2, 0, 3);  // Should become "ld"
    assert(test2->character == 'l');
    assert(test2->next->character == 'd');
    assert(test2->next->next == NULL);
    cout << "\nTest Case 2 Passed: Remove from start";

    // Test Case 3: Remove characters from end of list
    charCollection test3 = new listNode;
    test3->character = 'T';
    test3->next = new listNode;
    test3->next->character = 'e';
    test3->next->next = new listNode;
    test3->next->next->character = 's';
    test3->next->next->next = new listNode;
    test3->next->next->next->character = 't';
    test3->next->next->next->next = NULL;
    removeChars(test3, 2, 2);  // Should become "Te"
    assert(test3->character == 'T');
    assert(test3->next->character == 'e');
    assert(test3->next->next == NULL);
    cout << "\nTest Case 3 Passed: Remove from end";

    // Test Case 4: Empty list
    charCollection test4 = NULL;
    removeChars(test4, 0, 3);  // Should remain NULL
    assert(test4 == NULL);
    cout << "\nTest Case 4 Passed: Empty list";

    // Test Case 5: Remove zero length
    charCollection test5 = new listNode;
    test5->character = 'A';
    test5->next = NULL;
    removeChars(test5, 0, 0);  // Should remain unchanged
    assert(test5->character == 'A');
    assert(test5->next == NULL);
    cout << "\nTest Case 5 Passed: Zero length removal";

    // Test Case 6: Remove beyond list length
    charCollection test6 = new listNode;
    test6->character = 'X';
    test6->next = new listNode;
    test6->next->character = 'Y';
    test6->next->next = NULL;
    removeChars(test6, 5, 2);  // Should remain unchanged
    assert(test6->character == 'X');
    assert(test6->next->character == 'Y');
    assert(test6->next->next == NULL);
    cout << "\nTest Case 6 Passed: Position beyond list length";

    cout << "\nAll test cases passed successfully!";

    // Clean up memory
    delete test1;
    delete test2;
    delete test3;
    delete test4;
    delete test5;
    delete test6;
}

int main() {
	removeCharsTester();
}