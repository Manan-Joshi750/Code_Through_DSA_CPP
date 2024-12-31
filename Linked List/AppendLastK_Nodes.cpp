#include <iostream>
using namespace std;
//CODE TO APPEND LAST K NODES TO THE START OF THE LINKED LIST.
// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Function to insert a new node at the beginning of a linked list
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
// Function to append last k nodes to the start of the linked list
void appendLastKNodesToStart(Node*& head, int k) {
    if (head == nullptr || k <= 0) {
        cout << "Invalid input or empty list!" << endl;
        return;
    }

    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    if (k > length) {
        cout << "k is greater than the length of the list!" << endl;
        return;
    }

    int count = 0;
    temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        count++;
        if (count == length - k + 1) {
            if (prev != nullptr) {
                prev->next = nullptr;
                Node* newHead = temp;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = head;
                head = newHead;
            } else {
                // If the entire list is to be moved to the beginning
                return;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// Function to delete the linked list to free memory
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    int k = 3; // Number of nodes to move to the start
    appendLastKNodesToStart(head, k);

    cout << "After moving last " << k << " nodes to start: ";
    printList(head);

    deleteList(head); // Free memory by deleting the linked list
    return 0;
}
