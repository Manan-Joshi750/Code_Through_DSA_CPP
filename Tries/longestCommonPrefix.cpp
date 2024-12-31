#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    int childrenCount;

    TrieNode() {
        isTerminal = false;
        childrenCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
                node->childrenCount++;
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    string longestCommonPrefix() {
        TrieNode* node = root;
        string prefix = "";

        while (node && node->childrenCount == 1 && !node->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    prefix += (char)('a' + i);
                    node = node->children[i];
                    break;
                }
            }
        }
        return prefix;
    }
};

string findLongestCommonPrefix(const vector<string>& words) {
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }
    return trie.longestCommonPrefix();
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << findLongestCommonPrefix(words) << endl;

    return 0;
}