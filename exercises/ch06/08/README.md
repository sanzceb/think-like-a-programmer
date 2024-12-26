# Exercise 6.8: Recursive remove characters using Linked List

## Problem Statement

Design your own: Try to discover a linked-list processing problem that is
difficult to solve using iteration but can be solved directly using recursion.

## Analysis

The function I decided to implement is `removeChars`, implemented in exercise
[4-8][4-8]. The implemented definition is this:

```cpp
void removeChars(charCollection & list, int pos, int len);
```

The data structure will be the one [defined in exercise 4-8][4-8-1].

<!-- BRI Plan-->
1. If the list is empty or if there is nothing to remove, return. Otherwise
2. Make the recursive call with the rest of the list, reduce the position
3. If the first element must be removed, remove it.

## Solution Overview

For this implementation, I see quite interesting to make some comments:

```cpp
// remove a section of characters from a string based on
// the starting position and length
void removeChars(charCollection& s1, int pos, int len) {
    if (s1 == NULL) return;
    if (pos <= -len) return; //[1]
    removeChars(s1->next, pos - 1,  len); //[2]
    if (pos <= 0) { //[3]
        listNode * tmp = s1->next;
        delete s1;
        s1 = tmp;
    }
}

void removeChars(charCollection& s1, int pos, int len) { //[4]
    if (s1 == NULL) return;
    listNode * prevPtr = s1;
    while (prevPtr != NULL && pos-- > 1) {
        prevPtr = prevPtr->next;
    }
    if (prevPtr == NULL) return;
    while (prevPtr->next != NULL && len-- > 0) {
        listNode * newNext = prevPtr->next->next;
        delete prevPtr->next;
        prevPtr->next = newNext;
    }
}
```

[1] The second minimal case is when we do not have anything to remove. This
happens when we have reached a distance beyond `len` from the starting position.
We could use as the only minimal case the empty list, but it would cause an
unnecesary overhead. The lesser than check makes the function more robust
against bad inputs such as `len > pos`.

[2] Reducing the problem means in this case reducing the position argument,
since it is our way to keep track of the node we are at.

[3] The node candidates to be removed are the nodes whose position is between
0 and -len

[4] To illustrate the simplification, I have brought batch the iterative
implementation. Notice how we got rid of the complex loops using recursion.

Finally, it is also worth mentioning that the approach works with both head and
tail recursion. This might be something to consider in a language that does
benefit from tail over head recursion.

<!-- Links -->
[4-8]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch04/08)
[4-8-1]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch04/08/main.cpp)
