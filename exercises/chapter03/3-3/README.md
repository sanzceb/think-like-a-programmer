# Exercise 3.3: [Sorting Checker]

## Problem Statement
Write a `bool` function that is passed an array and the number of elements  
in that array and determines whether the data in the array is sorted. This  
should require only one pass!

## Approach
To solve this exercise I have chosen to rewrite the insertion sort algorithm  
 that is explained in the book and modify it. When insertion sort processes and  
 array that is already sorted, it only makes one pass!.
 ### Original Insertion Sort  
```cpp
    void insertion_sort(int intArray[], int ARRAY_SIZE) {
        int start = 0, end = ARRAY_SIZE - 1;
        for(int i = start + 1; i <= end; i++) {
            for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--) {
                int temp = intArray[j - 1];
                intArray[j - 1] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
```
 ### Bool function modified
```cpp
    bool is_sorted(int intArray[], int ARRAY_SIZE) {
        int start = 0, end = ARRAY_SIZE - 1;
        for(int i = start + 1; i <= end; i++) {
            for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--)
                return false;
        }
        return true;
    }
```
## Final Notes
I have provided a very basic test to test the functionality. C++ prints `bool`  
types as if they were integers.