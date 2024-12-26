# Exercise 6.6 Recursive Parity Checker Linked List

## Problem Statement

Solve exercise [6-1][6-1] again, using a linked list instead of an array.

## Analysis

To introduce the problem I will bring the definition of the string version:

```cpp
bool hasOddParity(string binaryStr);
```

The signature of our version with linked list will be:

```cpp
bool hasOddParity(listPtr binaryStr);
```

where the linked list, `listPtr` is defined like this:

```cpp
struct listNode {
    char data;
    listNode * next;
};

typedef listNode * listPtr;
```

For the resolution of the exercise I created a plan based on the *BRI*
framework (pg 159). It states as follows:

1. If the list has one bit, the parity will be **odd** if the bit **is 1**.
Otherwise ...
2. Use a recursive call to check if the parity of the rest of the list is
**odd**.
3. See whether the first bit is 1 or 0.
4. Use the results of 2 and 3 to check the parity of the whole list:

    4.1 If the first bit is 1, the parity will be **odd** if the parity of the
    rest of the list is **even**.

    4.2 If the first bit is 0, the parity will be **even** if the parity of the
    rest of the list is **odd**.

<!-- Links -->
[6-1]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter06/01)