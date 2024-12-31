#include <iostream>
using namespace std;

//Time Complexity of all of the three operations is O(length of the word)
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A'; // Assuming uppercase letters
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A'; // Assuming uppercase letters
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Helper function for deletion
    bool removeUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;
                // Check if it has any children
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Don't delete this node
                    }
                }
                return true; // Can delete this node
            }
            return false; // Word doesn't exist
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];
        
        if (child == NULL) {
            return false; // Word doesn't exist
        }

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            delete root->children[index];
            root->children[index] = NULL;

            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false;
                    }
                }
                return true; // Can delete this node
            }
        }
        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    
    cout << "Present or not (ARM): " << t->searchWord("ARM") << endl;
    
    t->removeWord("ARM");
    cout << "Present or not (ARM) after removal: " << t->searchWord("ARM") << endl;
    
    delete t;
    return 0;
}