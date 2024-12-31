#include <iostream>
#include <map>
#include <queue>
using namespace std;
//VERTICAL ORDER OF A BINARY TREE.
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Function to insert nodes into the hash map based on their horizontal distance
void verticalOrder(TreeNode* root, int hd, map<int, vector<int>>& m) {
    if (root == nullptr) return;
    // Insert current node's value into the hash map based on horizontal distance
    m[hd].push_back(root->val);
    // Recur for left and right subtrees with updated horizontal distances
    verticalOrder(root->left, hd - 1, m);
    verticalOrder(root->right, hd + 1, m);
}
// Function to print the vertical order of a binary tree
void printVerticalOrder(TreeNode* root) {
    if (root == nullptr) return;
    // Create a hash map to store nodes at different horizontal distances
    map<int, vector<int>> m;
    // Queue to perform level order traversal
    queue<pair<TreeNode*, int>> q;
    // Enqueue root and its horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int hd = temp.second;
        // Insert the node into the hash map
        m[hd].push_back(node->val);
        // Enqueue left and right children with updated horizontal distances
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    // Traverse the hash map and print nodes at each horizontal distance
    for (auto it = m.begin(); it != m.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Vertical order traversal is:\n";
    printVerticalOrder(root);
    return 0;
}
