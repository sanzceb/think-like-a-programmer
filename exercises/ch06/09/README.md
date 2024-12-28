# Exercise 6.9 Recursive Heap Checker

## Problem Statement

Some words in programming have more than one common meaning. In
Chapter 4, we learned about the heap, from which we get memory allocated
with new. The term heap also describes a binary tree in which each node value
is higher than any in the left or right subtree. Write a recursive function to
determine whether a binary tree is a heap.

## Data Structures

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

For simplicity and since these exercises are for learning purposes, I will work
only with **complete trees**.

## Solution Overview

This recursion has been a bit more difficult than the recursive problems of
linked lists, so it is worth make some comments:

```cpp
bool isAHeap(treePtr root) {
    if (root == NULL) return false; //[1]
    if (root->left == NULL && root->right == NULL) //[2]
        return true;    
    
    bool isLeftAHeap = isAHeap(root->left); //[3]
    bool isRightAHeap = isAHeap(root->right); //[4]
    bool isLeftMax = (root->data > root->left->data); //[5]
    bool isRightMax = (root->data > root->right->data); //[6]

    return isLeftAHeap && isRightAHeap && isLeftMax && isRightMax; //[7]
}
```

Here is the BRI I defined for the implementation:

[1] The problem does not consider an empty tree a valid heap. This is due to
the fact that empty trees cannot be considered sorted by any criteria.

[2] The minimal tree is a tree with one node, which it is a heap by definition.

[3],[4] Make recursive calls to get the answer from the subtrees.

[5], [6] Node inspection to check if the root is greater than the subtrees

[7] The tree is a heap if the root is greater than the subtrees and its
subtrees are heaps.

## Notes

The reason of making the recursive calls before the root inspection is to
illustrate better the *Big Recursive Idea* presented in the book (p.161). These
programs are meant to be educational for myself and for who is studying the
book and finds this repository by chance.

## Appendix: Test Cases

I had put at the end of the document the definition of each of the test cases,
whose code have been generated using AI. For simplicity, the implementations
only work with **complete trees**.

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
```

### Valid Tree - Complex Structure

```txt
     100
    /   \
   50    75
  /  \   / \
 20  30 40  60
```
