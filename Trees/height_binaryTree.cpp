#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree from a given input string
Node* buildTree(string str) {   
    // Corner Case: if the input is empty or starts with 'N'
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    
    // Create a vector of strings from the input string after splitting by spaces
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
    
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Start from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution {
public:
    // Function to find the height of a binary tree.
    int height(struct Node* node) {
        // Base case: If the node is NULL, the height is 0
        if (node == NULL) {
            return 0;
        }
        
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // The height of the tree is the maximum of the heights of the two subtrees plus 1 (for the current node)
        int treeHeight = max(leftHeight, rightHeight) + 1;
        return treeHeight;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.height(root) << endl;
    }
    return 0;
}