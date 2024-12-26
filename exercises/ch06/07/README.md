# Exercise 6.7 Recursive Target Count using Linked List

## Problem Statement

Solve exercise [6-3][6-3] again, using a linked list instead of an array.

## Analysis

This exercise is again a problem with integers, so I will bring back the linked
list of [exercise 5][6-5]:

```cpp
struct listNode {
    int data;
    listNode * next;
};

typedef listNode * listPtr;
```

Here is my function signature to solve the problem:

```cpp
int listTargetCount(listPtr list, int target);
```

<!-- BRI plan -->
As done in the previous exercise, I created a plan based on the *BRI* and it
states as follows:

1. If the list is empty the count will be 0, otherwise ...
2. Make a recursive call to count target in the rest of the list.
3. Inspect if the first node has the target.
4. Use the results of 2 and 3 to check the parity of the whole list.

## Notes

I have made the reports shorter for these exercises because I think the only
aspect worth mentioning is the followed plan. Each function follows the same
pattern that is visible in the implemention itself.

<!-- Links -->
[6-3]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch06/03)
[6-5]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch06/05)
