# include <iostream>
# include <cassert>

using std::cout;

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};

struct treeStats {
    int sum;
    int count;
};

typedef treeNode* treePtr;

treeStats stats(treePtr root) {
    treeStats _stats;
    if (root->left  == NULL && root->right == NULL) {
        _stats.sum = root->data;
        _stats.count = 1;
        return _stats;
    }

    treeStats leftStats = stats(root->left);
    treeStats rightStats = stats(root->right);
    
    _stats.sum = leftStats.sum + rightStats.sum + root->data;
    _stats.count = leftStats.count + rightStats.count + 1;
    
    return _stats;
}

double average(treePtr root) {
    if (root == NULL) return 0;
    treeStats rootStats = stats(root);
    double rootSum = rootStats.sum; // Smooth casting
    int rootCount = rootStats.count;
    return rootSum / rootCount;
}

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

void deleteTree(treePtr rootPtr) {
    if (rootPtr == NULL) return;
    deleteTree(rootPtr->left);
    deleteTree(rootPtr->right);
    delete rootPtr;
}


int main() {
    treePtr root = NULL;
    const int SIZE = 7;
    int numbers[SIZE] = {50, 25, 75, 20, 30, 72, 83};
    double sum = 0;
    cout << "Test case: Create a binary tree: ";
    for (int i = 0; i < SIZE; i++) {
        insert(root, numbers[i]);
        sum += numbers[i];
    }
    double avg = sum / SIZE;
    double recAvg = average(root);
    assert(avg == average(root) && "Averages are not correct");
    cout << "\nIterative average: " << avg;
    cout << "\nObtained average: " << recAvg;
    deleteTree(root);
}