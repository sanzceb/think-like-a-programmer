# Exercise 6.10 Binary Tree Checker

## Problem Statement

A *binary search tree* is a binary tree in which each node value is greater
than any value in that node’s left subtree but less than any value in the node’s
right subtree. Write a recursive function to determine whether a binary tree
is a binary search tree.

## Analysis
<!--Function definition-->
```cpp
struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;

bool isBinarySearchTree(treePtr rootPtr);
```
<!--BRI-->
<!-- 
If tree T is of minimal size, directly
assign a default value. Otherwise . . .
Make a recursive call to answer Q for the left subtree of T.
Make a recursive call to answer Q for the right subtree of T.
Inspect the value in the root node of T.
Use the results of the previous three steps to answer Q for all of T.

This
produces the following general plan. To
answer a question Q for tree T:
-->
BRI to answer if a tree $T$ is a binary search tree:

1. If a tree $T$ has only a single node, it is binary by default.
2. Make a recursive call to answer if the left subtree of T is binary.
3. Make a recursive call to answer if the right subtree of T is binary.
4. Inspect the node and check:

   4.1. The left subtree is binary, and the node is bigger than its maximum
   value.

   4.2. The right subtree is binary, and the node is smaller than its minimum
   value.

If both conditions are met, then `T` is a binary search tree.

## Solution Overview

```cpp
bool isBinarySearchTree(treePtr rootPtr) {
    if (rootPtr == NULL) return false;
    if (rootPtr->right == NULL && rootPtr->left == NULL) return true;
    if (rootPtr->left != NULL) {
        if (!isBinarySearchTree(rootPtr->left)) return false;
        if (rootPtr->data <= maxValue(rootPtr->left)) return false; //[1]
    }
    if (rootPtr->right != NULL) {
        if (!isBinarySearchTree(rootPtr->right)) return false;
        if (rootPtr->data >= minValue(rootPtr->right)) return false; //[2]
    }
    return true;
}
```

This problem is quite similar to the [heap problem][6-9] but there
is a big caveat. We must ensure than the node is maximum respect the left tree
[1] and minimum respect to the right tree [2]. This means we cannot just inspect
the immediate subnodes, we must traverse each subtree to check the maximum and
the minimum, and that implies two different recursive calls. A final observation
is that a binary search tree cannot allow duplicates so cases of equality
between nodes are excluded.

## Appendix: test cases

Test Case 3: Valid BST

```txt
     8
    / \
   3   10
  / \
 1   6
```

This represents a valid binary search tree where:

- All values in the left subtree (3, 1, 6) are less than 8
- All values in the right subtree (10) are greater than 8
- The subtree rooted at 3 maintains BST properties (1 < 3 < 6)

Test Case 4: Invalid BST (left subtree violation)

```txt
     8
    / \
   3   10
  / \
 1   9    <- Invalid: 9 is greater than root (8)
```

This tree violates the BST property because 9 appears in the left subtree of 8,
but 9 > 8.

Test Case 5: Invalid BST (right subtree violation)

```txt
     8
    / \
   3   10
      /
     7     <- Invalid: 7 is less than root (8)
```

This tree violates the BST property because 7 appears in the right subtree of 8, but 7 < 8.

Test Case 6: Invalid BST with duplicate values

```txt
     8
    / \
   8   8  <- Invalid: duplicate values
```

This tree violates the BST property because the value 3 appears twice.

Test Case 7: Deep valid BST

```txt
       10
      /  \
     5    15
    / \   / \
   3   7 13  17
  /
 1
```

This represents a valid binary search tree where:

- All values in the left subtree (5, 3, 7, 1) are less than 10
- All values in the right subtree (15, 13, 17) are greater than 10
- Each subtree recursively maintains the BST property
- No duplicate values exist

<!-- LINKS -->
[6-9]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch06/09)
