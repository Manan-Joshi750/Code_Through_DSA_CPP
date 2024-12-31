#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'value' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int value) {
        // Check whether the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return false;
        }
        else if (front == -1) { // First element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) { // Wrap around
            rear = 0;
        }
        else { // Normal flow
            rear++;
        }
        // Push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues front element from queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue() {
        if (front == -1) { // Check if the queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) { // Single element present, so when this is removed, queue becomes empty
            front = rear = -1;
        }
        else if (front == size - 1) { // Wrap around or we can say to maintian cyclic nature of the queue
            front = 0;
        }
        else { // Normal flow
            front++;
        }
        return ans;
    }
    
    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
    
    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    // Function to get the front element of the queue
    int getFront() {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (rear == -1) {
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    CircularQueue cq(5); // Creating a circular queue with size 5

    // Enqueue elements
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    // Dequeue elements
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 10
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 20

    // Enqueue more elements
    cq.enqueue(50);
    cq.enqueue(60);

    // Dequeue elements
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 30
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 40

    // Enqueue another element (should wrap around)
    cq.enqueue(70);

    // Check the front and rear elements
    cout << "Front element: " << cq.getFront() << endl; // Should print 50
    cout << "Rear element: " << cq.getRear() << endl;   // Should print 70

    // Dequeue the rest of the elements
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 50
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 60
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print 70

    // Check if the queue is empty
    if (cq.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Attempt to dequeue from an empty queue
    cout << "Dequeued: " << cq.dequeue() << endl; // Should print -1

    return 0;
}