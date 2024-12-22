# Exercise 4.5 [Remove Student Record]

## Problem Statement

Write a function `removeRecord` that takes a pointer to a `studentCollection`
and a student number and that removes the record with that student number from
the collection.

## Problem definition

Here are the data structures defined by the book to solve the problem:

```cpp
struct listNode {
    int studentNum;
    listNode * next;
};
typedef listNode * studentCollection;
```

Here is the definition of the function to implement:

```cpp
void removeRecord(studentCollection& sc, int studentNum);
```

## Solution Overview

This is one of those exercises where the difficulty is in make sure that we
address the edge cases properly. Here are the possible scenarios of removing a
record:

- The record is a node of the list. Most common.
- The record is found in the root.
- The record is not found.
- The collection is empty.

There is an important number of edge cases for such a simple action. So this is
typically a problem where it is easy to make mistakes. I myself overlooked the
case of finding the record in the root at the first try, for example. With that
in mind, we are going to review now my proposed solution:

```cpp
void removeRecord(studentCollection& sc, int studentNum) {
    if (sc != NULL) { //[1]
        //if(record found in root) [2]
        if (sc->studentNum == studentNum) {
            studentCollection newNext = sc->next;
            delete sc;
            sc = newNext;
        } else {
            // LIST SEARCH record
            listNode  *prevPtr = sc, *nextPtr = sc->next;
            while (nextPtr != NULL //[3]
                && nextPtr->studentNum != studentNum) {
                    prevPtr = nextPtr;
                    nextPtr = nextPtr->next;
            }
            //if(record found in next) [4]
            if (nextPtr != NULL) {
                listNode * newNext = nextPtr->next;
                delete nextPtr;
                prevPtr->next = newNext;
            }
        }
    }
 }
```

[1] If the collection is empty, the function must not try to perform any action.

[2] Removing the root record is not the same as removing a middle node. That is
why we handle as a special case.

[3] I implemented a search loop based on the search primitive we studied in the
chapter of arrays. The key difference here is that we additionaly need to
preserve a pointer to the previous node so that we can keep the links
between the nodes that go before and after the record we want to delete.

[4] A node is removed if only if the student has been found. Otherwise, the
function does not perform any action.

## Final thoughts

Here is one of those cases when I thought that the function was easier to
implement that what it turned out to be. As a takeaway, I should spend more time
thinking of edge cases when dealing with linked list exercises.
