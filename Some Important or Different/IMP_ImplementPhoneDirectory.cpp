#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    vector<string> suggestions;

    TrieNode() {
        isTerminal = false;
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

    void insert(const string& contact) {
        TrieNode* node = root;
        for (char ch : contact) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            if (node->suggestions.size() < 3) {
                node->suggestions.push_back(contact);
            }
        }
        node->isTerminal = true;
    }

    vector<vector<string>> getSuggestions(const string& prefix) {
        vector<vector<string>> result;
        TrieNode* node = root;
        
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                break;
            }
            node = node->children[index];
            result.push_back(node->suggestions);
        }

        // Fill in empty vectors if the prefix is not fully found in Trie
        while (result.size() < prefix.size()) {
            result.push_back({});
        }
        return result;
    }
};

class PhoneDirectory {
public:
    Trie trie;

    PhoneDirectory(const vector<string>& contacts) {
        for (const string& contact : contacts) {
            trie.insert(contact);
        }
    }

    vector<vector<string>> search(const string& prefix) {
        return trie.getSuggestions(prefix);
    }
};

int main() {
    vector<string> contacts = {"alice", "bob", "carol", "carl", "dave"};
    PhoneDirectory directory(contacts);

    string query = "ca";
    vector<vector<string>> suggestions = directory.search(query);

    cout << "Suggestions for prefix \"" << query << "\":" << endl;
    for (int i = 0; i < suggestions.size(); i++) {
        cout << "Prefix \"" << query.substr(0, i + 1) << "\": ";
        for (const string& suggestion : suggestions[i]) {
            cout << suggestion << " ";
        }
        cout << endl;
    }

    return 0;
}