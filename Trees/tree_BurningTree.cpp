/*Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values. */
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to create parent mapping and return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target) {
                res = current;
            }

            if (current->left) {
                nodeToParent[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                nodeToParent[current->right] = current;
                q.push(current->right);
            }
        }

        return res;
    }

    // Function to simulate burning the tree from the target node
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;

        int ans = 0;
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                // Check left child
                if (front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = true;
                }

                // Check right child
                if (front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = true;
                }

                // Check parent node
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag = true;
                }
            }

            if (flag) {
                ans++;
            }
        }

        return ans;
    }

    // Function to calculate minimum time to burn the tree from target node
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);

        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};

// Utility function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

int main() {
    Node* root = new Node(1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);

    Solution sol;
    int target = 5;
    cout << "Minimum time to burn the tree from target node " << target << " is: " << sol.minTime(root, target) << endl;

    return 0;
}