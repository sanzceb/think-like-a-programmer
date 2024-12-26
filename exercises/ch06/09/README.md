# Exercise 6.9 Recursive Heap Checker

## Problem Statement

Some words in programming have more than one common meaning. In
Chapter 4, we learned about the heap, from which we get memory allocated
with new. The term heap also describes a binary tree in which each node value
is higher than any in the left or right subtree. Write a recursive function to
determine whether a binary tree is a heap.

## Analysis

This will be the data structure used to implement binary trees:

```cpp
struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;
```

The definition of the function is:

```cpp
bool isAHeap(treePtr rootPtr);
```

Here is the BRI I defined for the implementation:

<!--BRI-->
1. The minimal tree is a tree with one node, which it is a heap by definition.
2. Make a recursive call to check if the left node is a heap and if the node
is bigger than the left subtree.
3. Make a recursive call to check if the right node is a heap and if the node
is bigger than the right subtree.
4. If 2 and 3 conditions are met, the tree is a heap.

## Solution Overview

This recursion has been a bit more difficult than the recursive problems of
linked lists, so it is worth make some comments:

```cpp
bool isAHeap(treePtr rootPtr) {
    if (rootPtr == NULL) return false; //[1]
    if (rootPtr->left == NULL && rootPtr->right == NULL) //[2]
        return true;
    if (rootPtr->left != NULL) { //[3]
        if (!isAHeap(rootPtr->left)) return false;
        if (rootPtr->data <= rootPtr->left->data) return false;
    }
    if (rootPtr->right != NULL) {
        if (!isAHeap(rootPtr->right)) return false;
        if (rootPtr->data <= rootPtr->right->data) return false;
    }
    return true;
}
```

[1]. The problem does not consider an empty tree a valid heap. This is due to
the fact that empty trees cannot be considered sorted by any criteria.

[2]. The trivial case is the one node tree, which is always a heap.

[3]. Since it is not mentioned in the statement, I had assumed that a tree
might not be complete and still meet the heap definition set by the author.
This might differ from classical definitions of what a heap is.

## Appendix: Test Cases

I had put at the end of the document the definition of each of the test cases,
whose code have been generated using AI.

### Basic Cases

1. Empty Tree (Invalid)
2. Single Node Tree (Valid)

### Valid Tree - Basic Structure

```txt
     50
    /  \
   20   30
  /  \
 10   15
```

### Invalid Tree - Subtree Violation

```txt
     30
    /  \
   40   20
   /
  10
```

### Valid Tree - Complex Structure

```txt
     100
    /   \
   50    75
  /  \   /
 20  30 40
```
