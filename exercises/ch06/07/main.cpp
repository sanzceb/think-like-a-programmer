#include <iostream>
#include <cassert>

using std::cout;

struct listNode {
    int data;
    listNode * next;
};

typedef listNode * listPtr;

int listTargetCount(listPtr list, int target) {
    if (list == NULL) return 0;
    int targetCount = listTargetCount(list->next, target);
    if (list->data == target) targetCount++;
    return targetCount;
}

// AI generated tests
void testListTargetCount() {
    // Test Case 1: Normal case with multiple occurrences
    listPtr test1 = new listNode;
    test1->data = 1;
    test1->next = new listNode;
    test1->next->data = 2;
    test1->next->next = new listNode;
    test1->next->next->data = 3;
    test1->next->next->next = new listNode;
    test1->next->next->next->data = 2;
    test1->next->next->next->next = new listNode;
    test1->next->next->next->next->data = 4;
    test1->next->next->next->next->next = new listNode;
    test1->next->next->next->next->next->data = 2;
    test1->next->next->next->next->next->next = new listNode;
    test1->next->next->next->next->next->next->data = 5;
    test1->next->next->next->next->next->next->next = NULL;
    assert(listTargetCount(test1, 2) == 3);
    cout << "\nTest Case 1 Passed: Multiple occurrences";

    // Test Case 2: Target not present in list
    listPtr test2 = new listNode;
    test2->data = 1;
    test2->next = new listNode;
    test2->next->data = 3;
    test2->next->next = new listNode;
    test2->next->next->data = 5;
    test2->next->next->next = new listNode;
    test2->next->next->next->data = 7;
    test2->next->next->next->next = new listNode;
    test2->next->next->next->next->data = 9;
    test2->next->next->next->next->next = NULL;
    assert(listTargetCount(test2, 2) == 0);
    cout << "\nTest Case 2 Passed: Target not present";

    // Test Case 3: Empty list
    listPtr test3 = NULL;
    assert(listTargetCount(test3, 5) == 0);
    cout << "\nTest Case 3 Passed: Empty list";

    // Test Case 4: List with single element equal to target
    listPtr test4 = new listNode;
    test4->data = 7;
    test4->next = NULL;
    assert(listTargetCount(test4, 7) == 1);
    cout << "\nTest Case 4 Passed: Single element equal to target";

    // Test Case 5: List with single element not equal to target
    listPtr test5 = new listNode;
    test5->data = 3;
    test5->next = NULL;
    assert(listTargetCount(test5, 7) == 0);
    cout << "\nTest Case 5 Passed: Single element not equal to target";

    // Test Case 6: All elements equal to target
    listPtr test6 = new listNode;
    test6->data = 4;
    test6->next = new listNode;
    test6->next->data = 4;
    test6->next->next = new listNode;
    test6->next->next->data = 4;
    test6->next->next->next = new listNode;
    test6->next->next->next->data = 4;
    test6->next->next->next->next = new listNode;
    test6->next->next->next->next->data = 4;
    test6->next->next->next->next->next = NULL;
    assert(listTargetCount(test6, 4) == 5);
    cout << "\nTest Case 6 Passed: All elements equal to target";

    // Test Case 7: Negative numbers
    listPtr test7 = new listNode;
    test7->data = -1;
    test7->next = new listNode;
    test7->next->data = -2;
    test7->next->next = new listNode;
    test7->next->next->data = -2;
    test7->next->next->next = new listNode;
    test7->next->next->next->data = -3;
    test7->next->next->next->next = new listNode;
    test7->next->next->next->next->data = -2;
    test7->next->next->next->next->next = new listNode;
    test7->next->next->next->next->next->data = -4;
    test7->next->next->next->next->next->next = NULL;
    assert(listTargetCount(test7, -2) == 3);
    cout << "\nTest Case 7 Passed: Negative numbers";

    // Test Case 8: Large numbers
    listPtr test8 = new listNode;
    test8->data = 1000000;
    test8->next = new listNode;
    test8->next->data = 999999;
    test8->next->next = new listNode;
    test8->next->next->data = 1000000;
    test8->next->next->next = new listNode;
    test8->next->next->next->data = 999998;
    test8->next->next->next->next = NULL;
    assert(listTargetCount(test8, 1000000) == 2);
    cout << "\nTest Case 8 Passed: Large numbers";

    cout << "\nAll test cases passed successfully!";

    // Clean up memory
    delete test1;
    delete test2;
    delete test3; // No effect since NULL
    delete test4;
    delete test5;
    delete test6;
    delete test7;
    delete test8;
}

int main() {
    testListTargetCount();
}
