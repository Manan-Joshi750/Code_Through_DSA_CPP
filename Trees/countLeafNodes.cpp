#include<iostream>
using namespace std;

// Definition for a binary tree node.
template <typename T>
class BinaryTreeNode {
  public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // Constructor
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // Destructor
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Function to perform in-order traversal and count leaf nodes (WE CAN MAKE USE OF ANY TRAVERSAL FOR ACCESSING THE NODES)
void inorder(BinaryTreeNode<int> *root, int &count) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, count);
    // Check if it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        count++;
    }

    inorder(root->right, count);
}

// Function to return the number of leaf nodes in the binary tree
int noOfLeafNodes(BinaryTreeNode<int> *root) {
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

// Function to build a binary tree from user input (helper function for testing)
BinaryTreeNode<int>* buildTree() {
    int data;
    cout << "Enter data (-1 for no node) : ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);

    cout << "Enter left child of " << data << ": ";
    newNode->left = buildTree();

    cout << "Enter right child of " << data << ": ";
    newNode->right = buildTree();

    return newNode;
}

int main() {
    BinaryTreeNode<int>* root = buildTree();
    cout << "Number of leaf nodes: " << noOfLeafNodes(root) << endl;
    // Cleanup: free the memory allocated for the tree
    delete root;
    return 0;
}