#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    // Node structure definition
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(NULL), right(NULL) {}
    };

    Node* root;

    // Constructor to build the tree using the parent array
    TreeAncestor(int n, vector<int>& parent) {
        root = new Node(0);
        unordered_map<int, Node*> nodes;
        nodes[0] = root;

        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(i);
            nodes[i] = newNode;
            Node* parentNode = nodes[parent[i]];

            if (!parentNode->left) {
                parentNode->left = newNode;
            } else {
                parentNode->right = newNode;
            }
        }
    }
    
    // Function to find the k-th ancestor of a given node
    int getKthAncestor(int node, int k) {
        return kthAncestor(root, k, node);
    }

private:
    // Recursive function to solve the problem
    Node* solve(Node* root, int &k, int node) {
        if (root == NULL)
            return NULL;
        
        if (root->data == node)
            return root;
        
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        if (leftAns != NULL && rightAns == NULL) {
            k--;
            if (k <= 0) {
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        
        if (leftAns == NULL && rightAns != NULL) {
            k--;
            if (k <= 0) {
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        
        return NULL;
    }

    // Wrapper function for solving the problem
    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        if (ans == NULL || ans->data == node)
            return -1;
        else
            return ans->data;
    }
};

// Driver Code
int main() {
    int n = 7; // number of nodes
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2}; // parent array

    TreeAncestor* obj = new TreeAncestor(n, parent);

    // Example usage
    cout << obj->getKthAncestor(3, 1) << endl; // Output: 1 (1st ancestor of node 3)
    cout << obj->getKthAncestor(5, 2) << endl; // Output: 0 (2nd ancestor of node 5)
    cout << obj->getKthAncestor(6, 3) << endl; // Output: -1 (3rd ancestor of node 6 does not exist)

    return 0;
}