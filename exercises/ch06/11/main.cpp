#include <iostream>
#include <cassert>

using std::cout;

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;

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

// Helper functions to do the test

bool isBinarySearchTree(treePtr root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return true;    
    
    bool isLeftBinary = isBinarySearchTree(root->left);
    bool isRightBinary = isBinarySearchTree(root->right);
    bool isLeftMax = root->left->data < root->data;
    bool isRightMin = root->right->data > root->data;

    return isLeftBinary && isRightBinary && isLeftMax && isRightMin;
}

void deleteTree(treePtr rootPtr) {
    if (rootPtr == NULL) return;
    deleteTree(rootPtr->left);
    deleteTree(rootPtr->right);
    delete rootPtr;
}

int main() {
    treePtr root = NULL;
    const int SIZE = 7;
    int numbers[SIZE] = {50, 25, 75, 20, 30, 70, 80};
    
    cout << "Test case: Create a binary tree: ";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nInserting number: " << numbers[i];
        insert(root, numbers[i]);
    }

    assert(isBinarySearchTree(root) && "The tree must be kept binary");
    cout << "\nTest Passed!\n";
    deleteTree(root);
}