#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    // METHOD - 1
    Node* copyListUsingMap(Node* head) {
        // Create a clone list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;
        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Create a map to map original nodes to cloned nodes
        unordered_map<Node*, Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != nullptr && cloneNode != nullptr) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Arrange all the random pointers
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != nullptr) {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }

    // METHOD - 2
    Node* copyListUsingConstantSpace(Node* head) {
        // Create a clone list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;
        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Adding nodes of cloned list in original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }

        // Copy all the random pointers
        temp = head;
        cloneNode = cloneHead;
        while (temp != nullptr) {
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        //Revert changes done in step 2
        originalNode = head;
        cloneHead = head->next;
        cloneNode = cloneHead;

        while (originalNode != nullptr) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if (cloneNode->next != nullptr) {
                cloneNode->next = cloneNode->next->next;
                cloneNode = cloneNode->next;
            }
        }

        return cloneHead;
    }

private:
    void insertAtTail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

// Function to print the list along with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Node value: " << temp->val;
        if (temp->random != nullptr)
            cout << ", Random points to: " << temp->random->val << endl;
        else
            cout << ", Random points to: NULL" << endl;
        temp = temp->next;
    }
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up random pointers
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next->next->next; // 3's random points to 4
    head->next->next->next->random = head->next; // 4's random points to 2

    cout << "USING EXTRA SPACE....." << endl << endl;
    cout << "Original List:\n";
    printList(head);

    // Copy the linked list
    Solution sol;
    Node* clonedHead = sol.copyListUsingMap(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    cout << endl;
    cout << "USING CONSTANT SPACE....." << endl << endl;

    // Copy the linked list;
    clonedHead = sol.copyListUsingConstantSpace(head);
    cout << "Original List:\n";
    printList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}