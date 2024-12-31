/*
Given a string S of distinct characters of size N and their corresponding frequencies f[] 
(i.e., character S[i] has f[i] frequency). Your task is to build the Huffman tree and print 
all the Huffman codes in preorder traversal of the tree.

Note: 
1. While merging, if two nodes have the same frequency, then the node which occurs first 
   will be taken on the left of the Binary Tree and the other one to the right.
2. Otherwise, the node with less frequency will be taken on the left of the subtree and 
   the other one to the right.
*/

#include <bits/stdc++.h>
using namespace std;

// Node structure for the Huffman tree
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->data > b->data; // Lexicographical order for same frequency
        return a->freq > b->freq;    // Node with smaller frequency has higher priority
    }
};

// Function to generate Huffman codes
void generateHuffmanCodes(Node* root, string code, vector<pair<char, string>>& result) {
    if (!root) return;

    // If it's a leaf node, store the character and its code
    if (!root->left && !root->right) {
        result.push_back({root->data, code});
    }

    // Traverse left and right subtrees
    generateHuffmanCodes(root->left, code + "0", result);
    generateHuffmanCodes(root->right, code + "1", result);
}

// Main function to build the Huffman tree and generate codes
vector<pair<char, string>> huffmanCodes(string S, vector<int>& f) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for each character and push it to the priority queue
    for (int i = 0; i < S.size(); i++) {
        pq.push(new Node(S[i], f[i]));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Merge the two nodes
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    // The root of the tree
    Node* root = pq.top();

    // Generate Huffman codes in preorder traversal
    vector<pair<char, string>> result;
    generateHuffmanCodes(root, "", result);

    return result;
}

int main() {
    string S;
    cout << "Enter the characters: ";
    cin >> S;

    int N = S.size();
    vector<int> f(N);
    cout << "Enter their frequencies: ";
    for (int i = 0; i < N; i++) {
        cin >> f[i];
    }

    vector<pair<char, string>> codes = huffmanCodes(S, f);

    cout << "Huffman Codes in Preorder Traversal:\n";
    for (auto& code : codes) {
        cout << code.first << ": " << code.second << endl;
    }

    return 0;
}