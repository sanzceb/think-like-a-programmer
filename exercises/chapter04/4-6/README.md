# Exercise 4.6 [Linked-List String]

## Problem Statement

Let's create an implementation for strings that uses a linked list of characters
instead of dynamically allocated arrays. So we'll have a linked list where the
data payload is a single `char`; this will allow strings to grow without having
to recreate the entire string. We'll start by implementing the `append` and
`characterAt` functions.

## Data Structures & Definitions

Here are my proposed data structures for the implementation:

```cpp
struct listNode {
    char character;
    listNode * next;
};
typedef listNode * charCollection;
```

Here is the definition of the proposed functions:

```cpp
char characterAt(charCollection cc, int p); //[1]

void append(charCollection& cc, char c); //[2]
```

[1] Returns the character at position p in the collection, or `0`
if position doesn't exist.

[2] Adds a character to the end of the collection

## Linked-Lists vs Arrays

Before going straight into the solution, it is a good idea to remember the key
differences between linked lists and arrays:

- No need of recreating the whole collection each time it grows.
- No need of copy when the collection is resized.
- No random access. The only way to lookup a value is through list traversal.
- Storing a new character now requires list traversal (to replace the random
access) and memory allocation for one node.

With this in mind, we can go back to the previous implementation and analyze the
the required changes.

```cpp
char characterAt(arrayString s, int position) {
    return s[position]; // [1]
}

void append(arrayString& arrayStr, char charValue) {
    int oldLength = length(arrayStr); // [2]
    arrayString newArrayStr = new char[oldLength + 2]; //[3]
    for (int i = 0; i < oldLength; i++) { //[4]
        newArrayStr[i] = arrayStr[i];
    }
    newArrayStr[oldLength] = charValue; //[5]
    newArrayStr[oldLength + 1] = 0; //[6]
    delete[] arrayStr; //[7]
    arrayStr = newArrayStr;
}
```

[1] We do not dispose of random access. It needs to be replaced by list
traversal

[2] The length was required to compute in order to allocate memory. With a
linked-list this is not needed.

[3], [4], [7] Array allocation and array copies are also actions not needed
with linked-lists. We allocate memory exactly for one node at a time as we need
it.

[5] Here we will need to implement list traversal + node allocation to replace
store operation.

[6] Storing the null-character is not needed. Linked-Lists work with null
pointers

## Solution Overview

The preanalysis of the prior solution was really helpful to clarify ideas
and setup a plan. Despite that, the implementation was not a walk in the park.
As usual these linked-list functions have edge cases that can be tricky to
handle if we do not plan. Here's the code for `characterAt`:

```cpp
char characterAt(charCollection cc, int p) {
    if (cc == NULL) return 0; //[1]    
    listNode * searchPtr = cc; //[2] 
    while (searchPtr != NULL && p-- > 0) {
        searchPtr = searchPtr->next;
    }
    if (searchPtr != NULL) { //[3]
        return searchPtr->character;
    }  
    return 0; //[4]
}
```

[1],[4] The edge cases where the list is empty or the end of the list has been
reached are handled by returning the null-character value.

[2],[3] The common case is to search for the position and find it somewhere in
the list

Now let's go with the solution for `append`:

```cpp
void append(charCollection& cc, char c) {
    //if(list is empty)
    if (cc == NULL) {
        // CREATE the list
        cc = new listNode;
        cc->character = c;
        cc->next = NULL;
    } else {
        // RETRIEVE last node
        listNode * lastPtr = cc;
        while(lastPtr->next != NULL) {
            lastPtr = lastPtr->next;
        }
        // ADD new node
        listNode * newLastPtr = new listNode;
        newLastPtr->character = c;
        newLastPtr->next = NULL;
        lastPtr->next = newLastPtr;
    }
}
```

In the append function there is only one edge case, but which might be tricky
to detect. If we have an empty list, we need to create it by updating the
`NULL` pointer. When the list is created, the common scenario always works:
Retrieve the last node and update its `next` reference.

## Final thoughts

This exercise is the first of a series of three to build up a Linked-List String
API. I think it has been a good idea to break it down into three exercises.
Although the implementation of these functions was not particularly difficult,
it required deep thinking and a methodical approach.

The next exercise will be the implementation of `concatenate`. This function
will be more difficult, but with the foundation built up in this exercise
I feel confident on solving following the same method I applied here.
