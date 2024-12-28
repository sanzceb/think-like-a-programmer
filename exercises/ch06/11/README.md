# Exercise 6.11 Binary Tree Node Inserter

## Problem Statement

Write a recursive function that is passed a binary search tree's root pointer
and a new value to be inserted and that creates a new node with the new value,
placing it in the correct location to mantain the binary search tree structure.
Hint: Consider making the root pointer parameter a reference parameter.

## Analysis

```cpp
struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;

void insert(treePtr& rootPtr, int newValue);
```

## Solution Overview

Here is the code to illustrate the *BRI*.

```cpp
void insert(treePtr& root, int newValue) {
    if (root == NULL) {
        root = new treeNode;
        root->data = newValue;
        root->left = NULL;
        root->right = NULL;
    } else if (root->data < newValue){
        insert(root->right, newValue);
    } else if (root->data > newValue) {
        insert(root->left, newValue);
    }
}
```
<!--BRI-->
The *BRI* I defined states as follows: Given a binary search tree $T$, and a
value $V$:

1. $T$ is minimal, ($T$ is **empty**), create a new tree with $V$.
Otherwise:

   1.1 If $V$ is smaller than the node, insert it in the left
   subtree.

   1.2 If $V$ is bigger than the node, insert it in the right subtree.

Contrary to previous problems, this time we consider an empty tree meaningful
and minimal. Each problem has its considerations and different cases, despite of
working with the same data structure.

Regarding the testing, I made this time a different test. I reused the binary
search function as a tester. The function must be capable of creating a
complete tree structure from an array and keep it binary.
