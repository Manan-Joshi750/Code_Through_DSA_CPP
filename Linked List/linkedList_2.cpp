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

    //Destructor
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next  = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
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

int getLength(Node* &head){
    Node* temp  = head;
    int currentLength = 0;
    while(temp != NULL){
        currentLength++;
        temp = temp -> next;
    }

    return currentLength;
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

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    } else {
        Node* current = head;
        Node* previous = NULL;

        int count = 1;
        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        }

        current -> prev = NULL;
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    insertAtHead(head, tail, 9);
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    insertAtHead(head, tail, 8);
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    insertAtTail(tail, head, 11);
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    insertAtPosition(tail, head, 3, 12);
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    deleteNode(3, head);
    printLinkedList(head);
    cout << "Length of the current Linked list is : " << getLength(head) << endl;

    return 0;
}