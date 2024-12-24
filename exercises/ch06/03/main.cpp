#include <iostream>
#include <cassert>

using std::cout;

int iterativeArrayTargetCount(int array[], int size, int target) {
    int targetCount = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == target) targetCount++;
    }
    return targetCount;
}

int arrayTargetCount(int array[], int size, int target) {
    if (size == 0) return 0;
    int allButLastCount = arrayTargetCount(array, size - 1, target);

    if (array[size - 1] == target) {
        return allButLastCount + 1;
    } else {
        return allButLastCount;
    }
}

// The test cases are AI generated

void testArrayTargetCount() {
    // Test Case 1: Normal case with multiple occurrences
    {
        int arr1[] = {1, 2, 3, 2, 4, 2, 5};
        int size1 = 7;
        int target1 = 2;
        assert(arrayTargetCount(arr1, size1, target1) == 3);
        cout << "\nTest Case 1 Passed: Multiple occurrences";
    }

    // Test Case 2: Target not present in array
    {
        int arr2[] = {1, 3, 5, 7, 9};
        int size2 = 5;
        int target2 = 2;
        assert(arrayTargetCount(arr2, size2, target2) == 0);
        cout << "\nTest Case 2 Passed: Target not present";
    }

    // Test Case 3: Empty array
    {
        int arr3[] = {};
        int size3 = 0;
        int target3 = 5;
        assert(arrayTargetCount(arr3, size3, target3) == 0);
        cout << "\nTest Case 3 Passed: Empty array";
    }

    // Test Case 4: Array with single element equal to target
    {
        int arr4[] = {7};
        int size4 = 1;
        int target4 = 7;
        assert(arrayTargetCount(arr4, size4, target4) == 1);
        cout << "\nTest Case 4 Passed: Single element equal to target";
    }

    // Test Case 5: Array with single element not equal to target
    {
        int arr5[] = {3};
        int size5 = 1;
        int target5 = 7;
        assert(arrayTargetCount(arr5, size5, target5) == 0);
        cout << "\nTest Case 5 Passed: Single element not equal to target";
    }

    // Test Case 6: All elements equal to target
    {
        int arr6[] = {4, 4, 4, 4, 4};
        int size6 = 5;
        int target6 = 4;
        assert(arrayTargetCount(arr6, size6, target6) == 5);
        cout << "\nTest Case 6 Passed: All elements equal to target";
    }

    // Test Case 7: Negative numbers
    {
        int arr7[] = {-1, -2, -2, -3, -2, -4};
        int size7 = 6;
        int target7 = -2;
        assert(arrayTargetCount(arr7, size7, target7) == 3);
        cout << "\nTest Case 7 Passed: Negative numbers";
    }

    // Test Case 8: Large numbers
    {
        int arr8[] = {1000000, 999999, 1000000, 999998};
        int size8 = 4;
        int target8 = 1000000;
        assert(arrayTargetCount(arr8, size8, target8) == 2);
        cout << "\nTest Case 8 Passed: Large numbers";
    }

    cout << "\nAll test cases passed successfully!";
}

int main() {
    testArrayTargetCount();
}