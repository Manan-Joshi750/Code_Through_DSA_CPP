#include<iostream>
using namespace std;
/*Linked List is a linear data structure which is a collection of nodes where each node is representing data and every node has some address and this 
address will be the address of the next node which is having its own data and address as well and this is how it continues with the list being 
ending at the node which contains NULL as the address. 
It is basically a dynamic data structure which can grow or shrink during the runtime as well which results in no memory wastage. 
And insertion/deletion is easy in case of linked list as here we don't need to do any kind of shifting. 

Types of linked list are : 
Singly linked list, doubly linked list, circular linked list, circular doubly linked list. 

The theory which we have written above is basically for singly linked list that each node contains its own data and a address which points
towards the next node. But in case of an doubly linked list, each node has got its own data alongwith two pointers, previous pointer which points
towards the previous node and a next pointer which point towards the node present ahead/next to the current node. Then comes the case of circular 
linked list where the last node doesn't point to NULL, instead it point towards the first node. Talking about start/head is not logical here as in case 
of a circular linked list, we don't where it starts and where it ends. */

class Node {
    public:
    int data;
    Node* next;

    //Contructor
    Node (int data){
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node (){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    //insert at head
    if(position  == 1){
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
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

        previous -> next = current -> next;
        current -> next  = NULL;
        delete current;
    }
}

void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int main(){
    Node *node1 = new Node(10);
    cout << "Simple printing and checking....." << endl << endl;
    cout << node1 -> data << endl;
    cout << node1 -> next << endl << endl;

    cout << "Adding nodes at the starting, back and any random position....." << endl << endl;
    Node* head = node1;
    Node* tail = node1;
    printLinkedList(head);

    insertAtHead(head, 12);
    printLinkedList(head);

    insertAtTail(tail, 15);
    printLinkedList(head);

    insertAtPosition(tail, head, 3, 13);
    printLinkedList(head);

    insertAtPosition(tail, head, 4, 14);
    printLinkedList(head);
    cout << endl;

    cout << "Deleting nodes at a certain positon....." << endl << endl;
    deleteNode(4, head);
    printLinkedList(head);

    return 0;
}