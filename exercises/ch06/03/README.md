# Exercise 6.3 Recursive Target Count

## Problem Statement

Write a function that is passed an array of integers and a “target” number
and that returns the number of occurrences of the target in the array. Solve
the problem first using iteration, then recursion.

## Analysis

Here are the function signatures proposed:

```cpp
int iterativeArrayTargetCount(int array[], int size, int target);
int arrayTargetCount(int array[], int size, int target);
```

The implementation of the iterative problem is a criterion based search. Each
time an element has the target value, we increase a counter, which is what the
function must compute.

For the recursive implementation, I will establish the empty array as the base
case. In an empty array there cannot be occurrences, so the returned count will
always be zero.

## Solution Overview

Here is the iterative solution. After solving numerous array problems, this
problem was quite easy to implement:

```cpp
int arrayTargetCount(int array[], int size, int target) {
    int targetCount = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == target) targetCount++;
    }
    return targetCount;
}
```

After applying the *BRI* technique, here is the recursive solution:

```cpp
int arrayTargetCount(int array[], int size, int target) {
    if (size == 0) return 0; //[1]
    int allButLastCount = arrayTargetCount(array, size - 1, target);
    if (array[size - 1] == target) { //[2]
        return allButLastCount + 1;
    } else {
        return allButLastCount;
    }
}
```

[1] As discussed in the analysis, the trivial case should be the empty array.
The combination of the results [2] is easier than in the case of the bit
parity. We add 1 only if the last element coincides with the target otherwise
we return the count of the rest of the array.
