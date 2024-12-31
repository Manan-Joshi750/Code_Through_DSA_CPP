#include<iostream>
#include<map>
using namespace std;

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

void insertNode(Node* &tail, int element, int d){
    //assuming that this element exists in the list

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    } else {
        //non empty list
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        //element found and curr is on that element
        Node* temp = new Node(d);
        temp -> next =  curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout << "Cannot delete any node as the list is already empty" << endl;
        return;
    } else {
        //non empty list
        //assuming that value is present in the list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        //1 node linked list
        if(curr == prev){
            tail = NULL;
        }
        //>=2 node linked list
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void printLinkedList(Node* &tail){
    Node* temp = tail;
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

//Function to check whether a list is circular or not. 
bool isCircularList(Node* &head){
    if(head == NULL){
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }

    return false;
}

bool detectLoop(Node* &head){
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

bool floydDetectLoop1(Node* head) {
    if(head == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

Node* floydDetectLoop2(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop2(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
}

Node* removeLoop(Node* head){
    if(head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}

int main(){
    Node* tail = NULL;
    //Inserting in an empty list
    insertNode(tail, 5, 3);
    printLinkedList(tail);

    insertNode(tail, 3, 4);
    printLinkedList(tail);

    insertNode(tail, 4, 5);
    printLinkedList(tail);

    insertNode(tail, 5, 6);
    printLinkedList(tail);

    insertNode(tail, 6, 7);
    printLinkedList(tail);

    deleteNode(tail, 3);
    printLinkedList(tail);

    if(isCircularList(tail)){
        cout << "Linked List Is Circular In Nature....." << endl;
    } else {
        cout << "Linked List Is Not Circular In Nature....." << endl;
    }

    if(detectLoop(tail)){
        cout << "Loop is present....." << endl;
    } else {
        cout << "Loop is not present....." << endl;
    }

    if(floydDetectLoop1(tail)){
        cout << "Loop is present....." << endl;
    } else {
        cout << "Loop is not present....." << endl;
    }

    Node* startingNode = getStartingNode(tail);
    cout << "Loop starts at " << startingNode -> data << endl;

    removeLoop(tail);
    printLinkedList(tail);

    return 0;
}