#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };
    
    Info largestBSTSubtreeHelper(TreeNode* root, int& maxSize) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};
        
        Info left = largestBSTSubtreeHelper(root->left, maxSize);
        Info right = largestBSTSubtreeHelper(root->right, maxSize);
        
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSize = left.size + right.size + 1;
            maxSize = max(maxSize, currentSize);
            return {true, currentSize, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }
        
        return {false, 0, 0, 0};
    }
    
    int largestBSTSubtree(TreeNode* root) {
        int maxSize = 0;
        largestBSTSubtreeHelper(root, maxSize);
        return maxSize;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Size of largest BST is: " << solution.largestBSTSubtree(root) << endl;

    return 0;
}