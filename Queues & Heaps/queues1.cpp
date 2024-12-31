/*Queue is a data structure which follows the FIFO technique (first in first out). It consists of two aspects : front and rear. 
Whenever we are going to push something to a queue, then it will be always at the rear and pop operation will always be carried out at the front. 
*/
#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear; 
    int size;
    
    public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {   
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main() {
    Queue q;
    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Print the front element
    cout << "Front element: " << q.front() << endl; // Should print 10

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 10
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 20

    // Print the front element again
    cout << "Front element: " << q.front() << endl; // Should print 30

    // Dequeue the last element
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 30

    // Check if the queue is empty
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Attempt to dequeue from an empty queue
    cout << "Dequeued: " << q.dequeue() << endl; // Should print -1

    return 0;
}