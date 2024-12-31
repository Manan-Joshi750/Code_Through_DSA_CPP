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
    // Function to merge two BSTs
    TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1, inorder2;
        
        // Step 1: Get the in-order traversal of both BSTs
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        // Step 2: Merge the two sorted arrays
        vector<int> mergedInorder = mergeInorders(inorder1, inorder2);
        
        // Step 3: Convert the merged sorted array to a balanced BST
        return sortedArrayToBST(mergedInorder, 0, mergedInorder.size() - 1);
    }

private:
    // Function to perform in-order traversal and store values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& inorderValues) {
        if (!root) return;
        inorderTraversal(root->left, inorderValues);
        inorderValues.push_back(root->val);
        inorderTraversal(root->right, inorderValues);
    }
    
    // Function to merge two sorted arrays
    vector<int> mergeInorders(const vector<int>& inorder1, const vector<int>& inorder2) {
        vector<int> merged;
        merged.reserve(inorder1.size() + inorder2.size());

        int i = 0, j = 0;
        while (i < inorder1.size() && j < inorder2.size()) {
            if (inorder1[i] < inorder2[j]) {
                merged.push_back(inorder1[i]);
                i++;
            } else {
                merged.push_back(inorder2[j]);
                j++;
            }
        }
        
        // Append remaining elements from inorder1
        while (i < inorder1.size()) {
            merged.push_back(inorder1[i]);
            i++;
        }

        // Append remaining elements from inorder2
        while (j < inorder2.size()) {
            merged.push_back(inorder2[j]);
            j++;
        }
        
        return merged;
    }
    
    // Function to convert sorted array to a balanced BST
    TreeNode* sortedArrayToBST(const vector<int>& mergedInorder, int start, int end) {
        if (start > end) return NULL;
        
        // Pick the middle element as the root of the current subtree
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(mergedInorder[mid]);
        
        // Recursively construct the left and right subtrees
        node->left = sortedArrayToBST(mergedInorder, start, mid - 1);
        node->right = sortedArrayToBST(mergedInorder, mid + 1, end);
        
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
    // Example: Normal BST 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    // Example: Normal BST 2
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    Solution solution;
    TreeNode* mergedRoot = solution.mergeBSTs(root1, root2);

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}