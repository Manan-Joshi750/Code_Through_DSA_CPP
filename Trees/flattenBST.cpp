#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* flattenBST(TreeNode* root) {
        vector<int> inorderValues;
        inorderTraversal(root, inorderValues);

        TreeNode* newRoot = new TreeNode(inorderValues[0]);
        TreeNode* curr = newRoot;

        for(int i=1; i<inorderValues.size(); i++){
            TreeNode* temp = new TreeNode(inorderValues[i]);
            curr -> left = NULL;
            curr -> right = temp;
            curr = temp;
        }

        curr -> left = NULL;
        curr -> right = NULL;

        return newRoot;
    }

private:
    void inorderTraversal(TreeNode* root, vector<int> &inorderValues) {
        if (!root) return;
        
        inorderTraversal(root -> left, inorderValues);
        inorderValues.push_back(root -> val);
        inorderTraversal(root -> right, inorderValues);
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution solution;
    TreeNode* flattenedRoot = solution.flattenBST(root); 

    printFlattened(flattenedRoot);  
    return 0;
}