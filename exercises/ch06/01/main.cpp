#include <iostream>
using std::cout;

// Compute the sum of just the positive numbers iteratively
int iterativeArrayPosSum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            sum += array[i];
        }
    }
    return sum;
}

// Compute the sum of just the positive numbers recursively
int recursiveArrayPosSum(int array[], int size) {
    if (size == 0) return 0;    
    int lastNum = recursiveArrayPosSum(array, size - 1);
    int last = 0;
    if (array[size - 1] > 0) {
        last = array[size - 1];
    }
    return last + lastNum; 
}

int main() {
    // Test Case 1: Array with all positive numbers
    int test1[] = {1, 2, 3, 4, 5};
    cout << "\nTest 1 - All positive numbers: " 
    << recursiveArrayPosSum(test1, 5);

    // Test Case 2: Array with mixed positive and negative numbers
    int test2[] = {-1, 2, -3, 4, -5, 6};
    cout << "\nTest 2 - Mixed numbers: " << recursiveArrayPosSum(test2, 6);

    // Test Case 3: Array with all negative numbers
    int test3[] = {-1, -2, -3, -4, -5};
    cout << "\nTest 3 - All negative numbers: " 
    << recursiveArrayPosSum(test3, 5);

    // Test Case 4: Empty array
    int test4[] = {};
    cout << "\nTest 4 - Empty array: " << recursiveArrayPosSum(test4, 0);

    // Test Case 5: Array with zero
    int test5[] = {-1, 0, 1, 2, -3};
    cout << "\nTest 5 - Array with zero: " << recursiveArrayPosSum(test5, 5);

    return 0;
}