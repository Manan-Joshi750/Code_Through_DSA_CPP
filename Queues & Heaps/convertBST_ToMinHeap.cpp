#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr) return;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void convertToMinHeap(TreeNode* root, vector<int>& inorder, int& index) {
    if (root == nullptr) return;
    
    // Replace the current node's data with the next element from the sorted array
    root->data = inorder[index++];
    
    // Traverse the left subtree (preorder)
    convertToMinHeap(root->left, inorder, index);
    
    // Traverse the right subtree (preorder)
    convertToMinHeap(root->right, inorder, index);
}

void convertBSTToMinHeap(TreeNode* root) {
    // Vector to store the inorder traversal of the BST
    vector<int> inorder;
    
    // Step 1: Get the inorder traversal of the BST (sorted order)
    inorderTraversal(root, inorder);
    
    // Step 2: Convert to Min Heap using preorder traversal
    int index = 0;
    convertToMinHeap(root, inorder, index);
}

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    
    vector<TreeNode*> queue;
    queue.push_back(root);
    
    int front = 0;
    while (front < queue.size()) {
        TreeNode* currentNode = queue[front++];
        cout << currentNode->data << " ";
        
        if (currentNode->left) queue.push_back(currentNode->left);
        if (currentNode->right) queue.push_back(currentNode->right);
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    cout << "Level Order Traversal of Original BST: " << endl;
    levelOrderTraversal(root);
    
    // Convert the BST to Min Heap
    convertBSTToMinHeap(root);
    
    cout << "Level Order Traversal after converting to Min Heap: " << endl;
    levelOrderTraversal(root);
    
    return 0;
}