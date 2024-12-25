# Exercise 6.5 Recursive Positive Sum with Linked-List

## Problem Statement

Solve exercise 6-1 again, using a linked list instead of an array.

## Analysis

As stated in the book, the way to divide a linked list so that we can reduce the
problem is one: The **first element of the list**, and the **rest of the list**.
Where in arrays we process the last element and reduce the size parameter, here
we only inspect the first element and make the recursive call passing `next`,
which represents the rest of the list and we can conceptually consider as
another list.

Additionally, I have implemented two helper methods to setup the linked list and
to facilitate the reuse of the test cases `asList` and `deleteList`. We will be
reusing these methods for the recursion exercises that make use of linked lists.

## Solution Overview

Here I will show the differences between the recursion using arrays and the
recursion using linked lists:

```cpp
// Compute the sum of just the positive numbers recursively
int recursiveArrayPosSum(int array[], int size) {
    if (size == 0) return 0; //[1]    
    int subSum = recursiveArrayPosSum(array, size - 1); //[2]
    if (array[size - 1] > 0) { //[3]
        return array[size - 1] + subSum;
    } else {
        return subSum; 
    }
}

int recursiveArrayPosSum(listPtr list) {
    if (list == NULL) return 0; //[1]
    int subSum = recursiveArrayPosSum(list->next); //[2]
    if (list->data > 0) { //[3]
        return list->data + subSum;
    } else {
        return subSum;
    }
}
```

[1] The trivial case is conceptually the same. When the structure is empty, we
return by default 0.

[2] Here is the first difference. Arrays are not reduceable, so we must pass the
whole array and reduce the size parameter. With dynamic structures such as
linked lists, we can send a reduced version of the structure without the need of
passing the size.

[3] Here is the other key difference. With arrays we inspect the last element
whereas with dynamic structures we look at the first element.
