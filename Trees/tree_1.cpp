/*Tree is a non-linear data structure where one node might be connected with various other nodes. 
The basic terminologies related to trees are as follows : 
--> Node : It is an entity of this tree data structure which contains a integer data value, a left pointer pointing towards its left child and 
similarly a right pointer pointing towards its right child. But this is for the case when it's a BINARY TREE, that is, it has only 2 child nodes. 
If the tree is having more than 2 child nodes, then it is known as an N-ARY TREE where the node structure would be like a integer data value and a list of 
all those child nodes. 
--> Root : The top most node of a tree is known as the root node. 
--> Children : The node which is present below any other node and is linked with that too. 
--> Parent : The node which is connected and present above this child node. 
--> Siblings : The nodes which are having same node as their parent node. 
--> Ancestors : Say we are at a certain node, so all those nodes which we will encounter which going strictly upwards would be the ancestors. 
--> Descendent : Same as ancestors but while going downwards. 
--> Leaf Node : The node which has no child. */
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

/*Level order traversal basically states that we access all the nodes of a tree level vise until we encounter a level which is having all NULL nodes.
This is also known as BFS(Breadth first search). */
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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

// Reverse level order traversal
void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        // Push right child first, then left child
        // This ensures that left subtree is processed before right subtree
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Print contents of stack
    while (!s.empty()) {
        node* temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}

/* 
          1            INORDER TRAVERSAL (LNR) :  7 3 11 1 17 5
        /   \          POSTORDER TRAVERSAL (LRN) : 7 11 3 17 5 1
       3     5         PREORDER TRAVERSAL (NLR) : 1 3 7 11 5 17
      / \   /          Basically L means go to the left part, R means go to the right part and N means print the value of the node on which you are present. 
     7   11 17   
*/

void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void inOrderTraversalIterative(node* root) {
    if (root == NULL) {
        return;
    }

    stack<node*> s;
    node* current = root;

    while (current != NULL || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = s.top();
        s.pop();
        cout << current->data << " ";
        // Visit the right subtree
        current = current->right;
    }
}

void preOrderTraversalIterative(node* root) {
    if (root == NULL) {
        return;
    }

    stack<node*> s;
    s.push(root);

    while (!s.empty()) {
        node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right child first so that left is processed first
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
}

void postOrderTraversalIterative(node* root) {
    if (root == NULL) {
        return;
    }

    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        node* current = s1.top();
        s1.pop();
        s2.push(current);

        // Push left and right children of removed item to s1
        if (current->left) {
            s1.push(current->left);
        }
        if (current->right) {
            s1.push(current->right);
        }
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void buildFromLevelOrder(node* &root1){
    queue<node*> q;
    int data;
    cout << "Enter data for the root node : " << endl;
    cin >> data;
    root1 = new node(data);
    q.push(root1);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout << endl;

    cout << "Showing level order traversal....." << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Showing reverse level order traversal....." << endl;
    reverseLevelOrderTraversal(root);
    cout << endl << endl;

    cout << ".....USING RECURSION....." << endl << endl;
    cout << "In Order Traversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal : ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal : ";
    postOrderTraversal(root);
    cout << endl << endl;

    cout << ".....USING ITERATION....." << endl << endl;
    cout << "In Order Traversal : ";
    inOrderTraversalIterative(root);
    cout << endl;

    cout << "Pre Order Traversal : ";
    preOrderTraversalIterative(root);
    cout << endl;

    cout << "Post Order Traversal : ";
    postOrderTraversalIterative(root);
    cout << endl << endl;

    cout << "Building a tree from level order traversal....." << endl << endl;
    node* root1 = NULL;
    buildFromLevelOrder(root1);
    levelOrderTraversal(root1);

    return 0;
}