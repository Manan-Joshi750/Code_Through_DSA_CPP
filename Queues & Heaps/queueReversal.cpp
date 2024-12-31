#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the queue
queue<int> rev(queue<int> q) {
    stack<int> s;

    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main() {
    queue<int> q;
    // Adding elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Display original queue
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    q = rev(q);

    // Display reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}