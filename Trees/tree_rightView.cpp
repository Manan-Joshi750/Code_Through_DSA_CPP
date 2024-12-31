#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

class Solution
{
public:
    void solve(Node* root, vector<int> &ans, int level) {
        if(root == NULL)
            return;
        
        if(level == ans.size())
            ans.push_back(root->data);
            
        solve(root->right, ans, level+1);    
        solve(root->left, ans, level+1);
    }

    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--) {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for(int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}