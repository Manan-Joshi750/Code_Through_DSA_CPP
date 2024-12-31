/*In case of a binary search tree, every node present to the left of the root node will be having smaller value as compared to the root node's value
and every node present to the right of the root node will be having greater value than the root node's value. 
IMPORTANT : InOrder Traversal of a binary search tree is always in the SORTED order. 
That means the value of left most node of a BST is the smallest and of right most node is the largest among all other node values in the entire BST. 

                                        Inorder Predecessor and Successor in a Binary Search Tree (BST):
--> Inorder Predecessor: The inorder predecessor of a node in a binary search tree is the node that comes just before the given node in an inorder traversal 
(which visits nodes in ascending order of their values).
--> Inorder Successor: The inorder successor of a node in a binary search tree is the node that comes just after the given node in an inorder traversal. 
                                                        Finding Predecessor and Successor:
Inorder Predecessor:
If the node has a left subtree, the predecessor is the rightmost node in the left subtree.
If the node does not have a left subtree, traverse up the ancestors until you find a node that is the right child of its parent. 
The parent of this node will be the predecessor.

Inorder Successor:
If the node has a right subtree, the successor is the leftmost node in the right subtree.
If the node does not have a right subtree, traverse up the ancestors until you find a node that is the left child of its parent. 
The parent of this node will be the successor. */
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        root -> right = insertIntoBST(root -> right, d);
    } else {
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void takeInput(Node* &root){
    cout << "Enter the data : ";
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cout << "Add more data : ";
        cin >> data;
    }
}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp -> left){
        temp = temp -> left;
    }

    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;
    while(temp -> right){
        temp = temp -> right;
    }

    return temp;
}

// Function to find the inorder predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (root == NULL) return;

    // If root's value is equal to the key
    if (root->data == key) {
        // Find the predecessor
        if (root->left != NULL) {
            Node* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            pre = tmp;
        }

        // Find the successor
        if (root->right != NULL) {
            Node* tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If the key is smaller than the root's value, the successor must be in the left subtree
    if (root->data > key) {
        suc = root; // This node could be the successor
        findPreSuc(root->left, pre, suc, key);
    }
    // If the key is greater than the root's value, the predecessor must be in the right subtree
    else {
        pre = root; // This node could be the predecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the created BST" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal : ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Minimum value in the above BST is : " << minValue(root) -> data << endl;
    cout << "Maximum value in the above BST is : " << maxValue(root) -> data << endl;

    int key;
    cout << "Enter the node value whose predecesor and succesor you want to find : ";
    cin >> key;
    Node* pre = NULL;
    Node* suc = NULL;
    findPreSuc(root, pre, suc, key);

    if (pre != NULL)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "Predecessor is NULL" << endl;

    if (suc != NULL)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "Successor is NULL" << endl;

    return 0;
}