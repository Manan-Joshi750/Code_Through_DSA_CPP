#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteBinaryTree(TreeNode* root, int index, int totalNodes) {
    if (!root) return true;

    // If index assigned to the current node is greater than total number of nodes, it's not CBT
    if (index >= totalNodes) return false;

    // Recursively check left and right subtrees with updated indices
    return isCompleteBinaryTree(root->left, 2 * index + 1, totalNodes) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, totalNodes);
}

bool isMaxHeap(TreeNode* root) {
    if (!root) return true;

    // If a leaf node, max heap property holds true
    if (!root->left && !root->right) return true;

    // If there is only a left child, check heap property between root and left child
    if (!root->right) {
        return root->val >= root->left->val && isMaxHeap(root->left);
    }

    // If there are both children, check heap property between root, left, and right children
    return root->val >= root->left->val &&
           root->val >= root->right->val &&
           isMaxHeap(root->left) &&
           isMaxHeap(root->right);
}

// Main function to check whether the binary tree is a heap
bool isBinaryTreeHeap(TreeNode* root) {
    if (!root) return true;

    // Total number of nodes in the tree
    int totalNodes = countNodes(root);

    // Check both CBT and Max Heap conditions
    return isCompleteBinaryTree(root, 0, totalNodes) && isMaxHeap(root);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    if (isBinaryTreeHeap(root)) {
        cout << "The binary tree is a max heap." << endl;
    } else {
        cout << "The binary tree is not a max heap." << endl;
    }
    
    return 0;
}