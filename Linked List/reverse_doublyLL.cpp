#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void printLinkedList(Node* &head){
    Node* temp  = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    //If list is empty
    if(head == NULL){
        Node* temp  = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
        Node* temp  = new Node(d);
        tail= temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* tail, Node* &head, int position, int d){
    //insert at head
    if(position  == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int nodeCount = 1;

    while(nodeCount < position - 1){
        temp = temp -> next;
        nodeCount++;
    }

    //insert at the end
    if(temp -> next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

Node* reverseDoublyLinkedList(Node* &head) {
    Node* current = head;
    Node* temp = NULL;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;
    }

    return head;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    printLinkedList(head);

    insertAtHead(head, tail, 9);
    printLinkedList(head);

    insertAtHead(head, tail, 8);
    printLinkedList(head);

    insertAtTail(tail, head, 11);
    printLinkedList(head);

    insertAtPosition(tail, head, 3, 12);
    printLinkedList(head);

    cout << "Doubly Linked List after getting reversed is : ";
    head = reverseDoublyLinkedList(head);
    printLinkedList(head);

    return 0;
}