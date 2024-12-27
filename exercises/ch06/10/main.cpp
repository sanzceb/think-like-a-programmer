#include <iostream>
#include <cassert>
#include <vector>

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;


int maxValue(treePtr rootPtr) {
    if (rootPtr == NULL)  return 0;
    if (rootPtr->right == NULL && rootPtr->left == NULL) 
        return rootPtr->data;
    int leftMax = maxValue(rootPtr->left);
    int rightMax = maxValue(rootPtr->right);
    int maxNum = rootPtr->data;
    if (leftMax > maxNum) maxNum = leftMax;
    if (rightMax > maxNum) maxNum = rightMax;
    return maxNum;
}

int minValue(treePtr rootPtr) {
    if (rootPtr == NULL)  return 0;
    if (rootPtr->right == NULL && rootPtr->left == NULL) 
        return rootPtr->data;
    int leftMin = minValue(rootPtr->left);
    int rightMin = minValue(rootPtr->right);
    int minNum = rootPtr->data;
    if (leftMin < minNum) minNum = leftMin;
    if (rightMin < minNum) minNum = rightMin;
    return minNum;
}

bool isBinarySearchTree(treePtr rootPtr) {
    if (rootPtr == NULL) return false;
    if (rootPtr->right == NULL && rootPtr->left == NULL) return true;
    if (rootPtr->left != NULL) {
        if (!isBinarySearchTree(rootPtr->left)) return false;
        if (rootPtr->data <= maxValue(rootPtr->left)) return false;
    }
    if (rootPtr->right != NULL) {
        if (!isBinarySearchTree(rootPtr->right)) return false;
        if (rootPtr->data >= minValue(rootPtr->right)) return false;
    }
    return true;
}

// Helper function to create a new node
treePtr createNode(int value) {
    treePtr newNode = new treeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Helper function to delete the tree and free memory
void deleteTree(treePtr root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void isBinarySearchTreeTester() {
    // Test Case 1: Empty tree
    std::cout << "Test Case 1: Empty tree" << std::endl;
    assert(isBinarySearchTree(nullptr) == false);
    std::cout << "Passed!" << std::endl;

    // Test Case 2: Single node
    std::cout << "Test Case 2: Single node" << std::endl;
    treePtr root = createNode(5);
    assert(isBinarySearchTree(root) == true);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    // Test Case 3: Valid BST
    std::cout << "Test Case 3: Valid BST" << std::endl;
    root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    assert(isBinarySearchTree(root) == true);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    // Test Case 4: Invalid BST (violates left subtree property)
    std::cout << "Test Case 4: Invalid BST (left subtree violation)" << std::endl;
    root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(9);  // Invalid: 9 > 8
    assert(isBinarySearchTree(root) == false);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    // Test Case 5: Invalid BST (violates right subtree property)
    std::cout << "Test Case 5: Invalid BST (right subtree violation)" << std::endl;
    root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->right->left = createNode(7);  // Invalid: 7 < 8
    assert(isBinarySearchTree(root) == false);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    // Test Case 6: Invalid BST with duplicate values
    std::cout << "Test Case 6: Invalid BST with duplicate values" << std::endl;
    root = createNode(8);
    root->left = createNode(8);
    root->right = createNode(8);
    assert(!isBinarySearchTree(root) == true);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    // Test Case 7: Deep tree with valid BST properties
    std::cout << "Test Case 7: Deep valid BST" << std::endl;
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(13);
    root->right->right = createNode(17);
    root->left->left->left = createNode(1);
    assert(isBinarySearchTree(root) == true);
    deleteTree(root);
    std::cout << "Passed!" << std::endl;

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    isBinarySearchTreeTester();
    return 0;
}