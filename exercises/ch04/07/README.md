# Exercise 4.7: [Linked-List concatenate]

## Problem Statement

Following up on the previous exercise, implement the `concatenate` function.
Note that if we make a call `concatenate(s1, s2)`, where both parameters are
pointers to the first node of the linked lists, the function should create a
copy of each of the nodes in `s2` and append them to the end of `s1`. That is,
the function should not simply point to the `next` field of the last node in
`s1`s list to the first node of `s2`s list.

## Data structures & Definitions

For the details about the data structures used, refer to the first part of the
implementation [here][ex4-6]. Here is the definition of the function we will
implement:

```cpp
void concatenate(charCollection& s1, charCollection s2);
```

The function should create a copy of each node of s2 and append it to s1. Here's
an illustrated example:

```cpp
s1: 't' -> 'e' -> 's' -> 't' -> NULL
s2: 'b' -> 'e' -> 'd' -> NULL

// After concatenate(s1, s2):
s1: 't' -> 'e' -> 's' -> 't' -> 'b' -> 'e' -> 'd' -> NULL
s2: 'b' -> 'e' -> 'd' -> NULL
```

## Array vs Linked-List approach

As we did in the previous exercise, let's analyze
the array implementation of `concatenate`:

```cpp
void concatenate(arrayString& s1, arrayString s2) {
    int s1Len = length(s1);
    int s2_Len = length(s2); //[1]
    int newS1_Len = s1Len + s2_Len + 1;
    // COPY s1
    arrayString newS1 = new char[newS1_Len]; //[2]
    for (int i = 1; i <= s1Len; i++) {
        newS1[i] = s1[i];
    }
    //COPY s2 next to s1
    for (int i = 1; i <= s2_Len; i++) { //[3]
        newS1[s1Len + i] = s2[i];
    }
    //STORE new length
    newS1[0] = newS1_Len + '0'; //[4]
    
    delete[] s1; //[5]
    s1 = newS1;
}
```

[1] The calculation of the lengths is not needed in Linked-Lists to allocate the
memory.

[2] Instead of memory allocation and copying, this step will be traverse the
list until we reach the last node, as done in the case of [append][ex4-6:append]

[3] The retrieval and copying of `s2` will be replaced by a traversal of `s2`,
copying the node at each step.

[4] No need of the null-character in linked lists. We will just point the `next`
value of the last node copy of `s2` to `NULL`.

[5] Linked-Lists do not replace structures, so we do not need to deallocate any
reference.

## Solution Overview

Here is my final solution, let's look at it step by step:

```cpp
void concatenate(charCollection& s1, charCollection s2) {
    if (s2 == NULL) return; //[1]
    listNode * last_s1Ptr = lastNode(s1); //[2]    
    listNode * loopPtr = s2;
    do { //[3]
        append(last_s1Ptr, loopPtr->character); //[4]
        loopPtr = loopPtr->next; //[5]
        last_s1Ptr = last_s1Ptr->next;
    } while(loopPtr != NULL);
}
```

[1] When there is nothing to concatenate, we return from the function as soon as
possible.

[2] This step is optional, but it improves the efficiency. If we
don't start at the last node, we would always be traversing s1 on each step.
I encapsulated the retrieval of the last node, since I find myself using it
repeatedely.

[3] I chose a do-while structure because we already check that `s2` is
not empty, so we are guaranteed to iterate at least once.

[4] The case of creating one node with a character and append it was already
implemented in the [previous exercise][ex4-6sol] so I decided to reuse it. It
simplified the implementation effort to avoid rethinking that problem.

[5] We update the pointer that traverses `s2` and the pointer to the last node
of `s1` so that avoid unnecessary traversals of `s1`.

## Final thoughts

This is one of those cases where I spent more time in refining the solution than
finding how to solve the problem. Thanks to the pre-analysis I was capable of
spotting the edge cases in advance and of noticing the flaws of my first
solution.

<!--Links UPDATE -->
[ex4-6]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-6)
[ex4-6:append]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-6#linked-lists-vs-arrays)
[ex4-6sol]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-6#solution-overview)
