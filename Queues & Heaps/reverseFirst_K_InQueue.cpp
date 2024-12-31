#include <bits/stdc++.h>
using namespace std;

// Function to reverse the first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    // Informing about the process of reversing the first k elements
    cout << "Reversing the first " << k << " elements of the queue..." << endl;

    // Push the first k elements from the queue into the stack
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Push the elements from the stack back into the queue (this reverses the order)
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Informing about rearranging the remaining elements
    cout << "Moving the remaining " << q.size() - k << " elements to the back of the queue..." << endl;

    // Move the remaining elements (n-k) from the front to the back of the queue
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    
    while (t-- > 0) {
        int n, k;
        // Prompting for the size of the queue and the number of elements to reverse
        cout << "Enter the size of the queue: ";
        cin >> n;
        cout << "Enter the number of elements to reverse: ";
        cin >> k;

        queue<int> q;

        // Prompting for the elements of the queue
        cout << "Enter the elements of the queue: ";
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            q.push(a);
        }

        // Informing the user that the queue is being modified
        cout << "Modifying the queue..." << endl;
        queue<int> ans = modifyQueue(q, k);

        // Displaying the modified queue
        cout << "Modified queue: ";
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
    
    return 0;
}