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

bool isBinarySearchTree(treePtr root);
```
<!--BRI-->
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
bool isBinarySearchTree(treePtr root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return true;    
    
    bool isLeftBinary = isBinarySearchTree(root->left);
    bool isRightBinary = isBinarySearchTree(root->right);
    bool isLeftMax = root->left->data < root->data; //[1]
    bool isRightMin = root->right->data > root->data; //[2]

    return isLeftBinary && isRightBinary && isLeftMax && isRightMin;
}
```

This problem is quite similar to the [heap problem][6-9] but there
is a big caveat. We must ensure than the node is maximum respect the left tree
[1] and minimum respect to the right tree [2]. The rest of aspects commented
for the heap problem apply here.

<!-- LINKS -->
[6-9]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch06/09)

## Appendix: Test Cases

### Test Case 1: Empty Tree

```txt
NULL
```

### Test Case 2: Single Node

```txt
   5
```

### Test Case 3: Simple BST

```txt
     20
    /  \
   10  30
```

This represents a valid binary search tree where each left child is less than
its parent and each right child is greater than its parent. The tree maintains
proper ordering with 10 < 20 < 30.

### Test Case 4: Simple Non-BST Tree

```txt
       50
      /  \
     20  30
    /  \
   10  15
```

This is not a valid binary search tree because the right subtree value (30) is
less than the root value (50), violating the BST property that all values in
the right subtree must be greater than the root.

### Test Case 5: Complex BST

```txt
       8
      / \
     4   12
    / \  / \
   2  6 10 14
```

This represents a valid binary search tree where the ordering property is
maintained throughout all levels. Each node's value is greater than every value
in its left subtree and less than every value in its right subtree, creating a
properly ordered structure: 2 < 4 < 6 < 8 < 10 < 12 < 14.

### Test Case 6: Complex Non-BST

```txt
       15
      /  \
     25   5
    / \  / \
   10  6 17 14
```

This is not a valid binary search tree due to multiple violations of the BST
property:

- The left child (25) is greater than the root (15)
- The right child (5) is less than the root (15)
- The subtree structure contains additional ordering violations
