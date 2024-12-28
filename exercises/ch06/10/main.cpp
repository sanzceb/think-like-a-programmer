#include <iostream>
#include <cassert>

using std::cout;

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;

bool isBinarySearchTree(treePtr root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return true;    
    
    bool isLeftBinary = isBinarySearchTree(root->left);
    bool isRightBinary = isBinarySearchTree(root->right);
    bool isLeftMax = root->left->data < root->data;
    bool isRightMin = root->right->data > root->data;

    return isLeftBinary && isRightBinary && isLeftMax && isRightMin;
}

treePtr createNode(int value) {
    treePtr newNode = new treeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void deleteTree(treePtr root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void isBinarySearchTreeTester() {
    cout << "Test Case 1: Empty tree";
    assert(isBinarySearchTree(nullptr) == false);
    cout << " Passed!";

    cout << "\nTest Case 2: Single node";
    treePtr root = createNode(5);
    assert(isBinarySearchTree(root) == true);
    deleteTree(root);
    cout << " Passed!";

    cout << "\nTest case 3: Simple BST:";
    root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    assert(isBinarySearchTree(root) && "Simple BST");
    deleteTree(root);
    cout << " Passed!";

    cout << "\nTest case 4: Simple non-BST tree:";
    root = createNode(50);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(10);
    root->left->right = createNode(15);
    assert(!isBinarySearchTree(root) && "Simple non-BST tree");
    deleteTree(root);
    cout << " Passed!";

    cout << "\nTest case 5: Complex BST tree:";
    root = createNode(8);
    root->left = createNode(4);
    root->right = createNode(12);   
    root->left->left = createNode(2);
    root->left->right = createNode(6);
    root->right->left = createNode(10);
    root->right->right = createNode(14);
    assert(isBinarySearchTree(root) && "Complex BST tree:");
    cout << " Passed!";
    deleteTree(root);

    cout << "\nTest case 6: Complex non-BST tree:";
    root = createNode(15);
    root->left = createNode(25);
    root->right = createNode(5);
    root->left->left = createNode(10);
    root->left->right = createNode(6);
    root->right->left = createNode(17);
    root->right->right = createNode(14);
    assert(!isBinarySearchTree(root) && "Complex non-BST tree:");
    cout << " Passed!";
    deleteTree(root);
    
    cout << "\nAll tests were passed!\n";
}

int main() {
    isBinarySearchTreeTester();
    return 0;
}