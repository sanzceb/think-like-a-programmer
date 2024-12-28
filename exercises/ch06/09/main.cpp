#include <iostream>
#include <cassert>

using std::cout;

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode* treePtr;

bool isAHeap(treePtr root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL)
        return true;    
    
    bool isLeftAHeap = isAHeap(root->left);
    bool isRightAHeap = isAHeap(root->right);
    bool isLeftMax = (root->data > root->left->data);
    bool isRightMax = (root->data > root->right->data);
    
    return isLeftAHeap && isRightAHeap && isLeftMax && isRightMax;
}

// Helper function to create a tree node
treePtr createNode(int value) {
    treePtr newNode = new treeNode;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to clean up the tree
void deleteTree(treePtr root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testIsAHeap() {
    // Test Case 1: Empty tree
    {
        treePtr emptyTree = NULL;
        assert(!isAHeap(emptyTree) && 
        "Empty tree should not be considered a valid heap");
    }

    // Test Case 2: Single node tree
    {
        treePtr singleNode = createNode(5);
        assert(isAHeap(singleNode) && 
        "Single node tree should be a valid heap");
        deleteTree(singleNode);
    }

    // Test Case 3: Valid tree where each node is greater than all nodes 
    // in its subtrees
    {
        treePtr root = createNode(50);
        root->left = createNode(20);
        root->right = createNode(30);
        root->left->left = createNode(10);
        root->left->right = createNode(15);
        assert(isAHeap(root) && 
        "Valid tree with correct greater-than-subtree property");
        deleteTree(root);
    }

    // Test Case 4: Invalid tree - node not greater than all in its subtree
    {
        treePtr root = createNode(30);
        root->left = createNode(40);  // 40 > 30
        root->right = createNode(20);
        assert(!isAHeap(root) && 
        "Should detect violation of greater-than-subtree property");
        deleteTree(root);
    }

    // // Test Case 5: Valid multi-level tree with multiple branches
    {
        treePtr root = createNode(100);
        root->left = createNode(50);
        root->right = createNode(75);
        root->left->left = createNode(20);
        root->left->right = createNode(30);
        root->right->left = createNode(40);
        root->right->right = createNode(60);
        assert(isAHeap(root) && 
        "Valid complex tree with correct greater-than-subtree property");
        deleteTree(root);
    }

    std::cout << "All test cases passed!" << '\n';
}

int main() {
    testIsAHeap();
    return 0;
}
