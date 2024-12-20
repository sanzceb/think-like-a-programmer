# Exercise 4.8: [Linked-List remove characters]

## Problem Statement

Add a function to the linked-list string implementation called `removeChars` to
remove a section of characters from a string based on the position and length.
For example, `removeChars(s1, 5, 3)` would remove the three characters starting
at the fifth character in the string. Make sure the removed nodes are properly
deallocated.

## Data structures & Definitions

For the details about the data structures used, refer to the first part of the
Linked-List series [here][ex4-6]

```cpp
void removeChars(charCollection& s1, int pos, int len);
```

These are two examples that will be used as test cases:

```cpp
s1: 't' -> 'e' -> 's' -> 't' -> 'b' -> 'e' -> 'd' -> NULL
// After removeChars(s1, 5, 2)
s1: 't' -> 'e' -> 's' -> 't' -> 'b'

s1: 't' -> 'e' -> 's' -> 't' -> 'b' -> 'e' -> 'd' -> NULL
// After removeChars(s1, 3, 3)
s1: 't' -> 'e' -> 's' -> 'd' -> NULL
```

## Solution Overview

The solution was broken down into two steps:

1. Traverse the list to the node prior to the first node that will be deleted.
This problem was solved when we implemented `characterAt` in
[exercise 6][ex4-6:charAt]

2. Traverse the section that starts at `pos` and finishes at `pos + len`
deleting `next` node at each step.

```cpp
void removeChars(charCollection& s1, int pos, int len) {
 if (s1 == NULL) return;
 // SEARCH for node prior to pos
    listNode * prevPtr = s1;
    while (prevPtr != NULL && pos-- > 1) { //[1]
        prevPtr = prevPtr->next;
    }
 //if(position not found)
 if (prevPtr == NULL) return;
 // remove each node between pos and len
 while (prevPtr->next != NULL && len-- > 0) { //[2]
        listNode * newNext = prevPtr->next->next;
  delete prevPtr->next;
  prevPtr->next = newNext;
    }
}
```

[1] By stopping at node pos - 1, we can delete the nodes while preserving the
integrity of the list.

[2] Starting from the previous node, we keep removing nodes until we have
removed a `len` number of nodes or if the end of the list is reached. What
happens earlier.

## Final Thoughts

This exercise closes the series of Linked-List exercises. The solution emerged
without much difficulty, because there was no step that we have not implemented
in some way in previous exercises. It is quite exciting feeling the progress I
have made since the start of the book.

<!--LINKS-->
[ex4-6]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-6)
[ex4-6:charAt]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-6#solution-overview)