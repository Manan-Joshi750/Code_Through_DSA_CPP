#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to convert a normal BST to a balanced BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderValues;
        // Step 1: Get the in-order traversal of the BST
        inorderTraversal(root, inorderValues);
        
        // Step 2: Convert the sorted array to a balanced BST
        return sortedArrayToBST(inorderValues, 0, inorderValues.size() - 1);
    }

private:
    // Function to perform in-order traversal and store values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& inorderValues) {
        if (!root) return;
        inorderTraversal(root->left, inorderValues);
        inorderValues.push_back(root->val);
        inorderTraversal(root->right, inorderValues);
    }
    
    // Function to convert sorted array to a balanced BST
    TreeNode* sortedArrayToBST(const vector<int>& inorderValues, int start, int end) {
        if (start > end) return NULL;
        
        // Pick the middle element as the root of the current subtree
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(inorderValues[mid]);
        
        // Recursively construct the left and right subtrees
        node->left = sortedArrayToBST(inorderValues, start, mid - 1);
        node->right = sortedArrayToBST(inorderValues, mid + 1, end);
        
        return node;
    }
};

// Helper function to print in-order traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example: Normal BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(30);

    Solution solution;
    TreeNode* balancedRoot = solution.balanceBST(root);

    // Print the in-order traversal of the balanced BST
    cout << "In-order traversal of balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}