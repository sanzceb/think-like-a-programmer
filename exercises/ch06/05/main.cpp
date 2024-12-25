#include <iostream>

using std::cout;

struct listNode {
    int data;
    listNode * next;
};

typedef listNode * listPtr;

// Initializes the linked list
listPtr asList(int array[], int size) {
    listPtr list = NULL;
    for (int i = 0; i < size; i++) {
        listNode * newPtr = new listNode;
        newPtr->data = array[i];
        newPtr->next = list;
        list = newPtr;
    }
    return list;
}
// delete the list
void deleteList(listPtr& list) {
    listNode * loopPtr = list;
    while (loopPtr != NULL) {
        listNode * tmpPtr = loopPtr->next;
        delete loopPtr;
        loopPtr = tmpPtr;
    }    
}

// Compute the sum of just the positive numbers recursively
int recursiveArrayPosSum(int array[], int size) {
    if (size == 0) return 0;    
    int subSum = recursiveArrayPosSum(array, size - 1);
    if (array[size - 1] > 0) {
        return array[size - 1] + subSum;
    } else {
        return subSum; 
    }
}

int recursiveArrayPosSum(listPtr list) {
    if (list == NULL) return 0;
    int subSum = recursiveArrayPosSum(list->next);
    if (list->data > 0) {
        return list->data + subSum;
    } else {
        return subSum;
    }
}

int main() {
    // Test Case 1: Array with all positive numbers
    int test1[] = {1, 2, 3, 4, 5};
    listPtr _list = asList(test1, 5);
    cout << "\nTest 1 - All positive numbers: " 
    << recursiveArrayPosSum(test1, 5) 
    << ' ' << recursiveArrayPosSum(_list);
    deleteList(_list);

    // Test Case 2: Array with mixed positive and negative numbers
    int test2[] = {-1, 2, -3, 4, -5, 6};    
    _list = asList(test2, 6);
    cout << "\nTest 2 - Mixed numbers: " 
    << recursiveArrayPosSum(test2, 6)
    << ' ' << recursiveArrayPosSum(_list);
    deleteList(_list);

    // Test Case 3: Array with all negative numbers
    int test3[] = {-1, -2, -3, -4, -5};
    _list = asList(test3, 5);
    cout << "\nTest 3 - All negative numbers: " 
    << recursiveArrayPosSum(test3, 5)
    << ' ' << recursiveArrayPosSum(_list);
    deleteList(_list);

    // Test Case 4: Empty array
    int test4[] = {};
    _list = asList(test4, 0);
    cout << "\nTest 4 - Empty array: " 
    << recursiveArrayPosSum(test4, 0)
    << ' ' << recursiveArrayPosSum(_list);
    deleteList(_list);

    // Test Case 5: Array with zero
    int test5[] = {-1, 0, 1, 2, -3};
    _list = asList(test5, 5);
    cout << "\nTest 5 - Array with zero: " 
    << recursiveArrayPosSum(test5, 5)
    << ' ' << recursiveArrayPosSum(_list);
    deleteList(_list);

    return 0;
}