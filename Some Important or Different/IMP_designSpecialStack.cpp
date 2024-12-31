/*Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), 
top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.
Implement the following public functions :
1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
2. pop() :
It pops the element from the top of the stack and returns nothing.
3. top() :
It returns the element being kept at the top of the stack.
4.  getMin() :
It returns the smallest element present in the stack.
Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)
Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)
Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)
Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function). */
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class SpecialStack {
    // Data members
    stack<int> s;
    int mini = INT_MAX;

public:
    /*----------------- Public Functions of SpecialStack -----------------*/
    void push(int data) {
        // For the first element
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2 * data - mini);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) {
            return -1; // Stack underflow
        }

        int curr = s.top();
        s.pop();
        if (curr > mini) {
            return curr;
        } else {
            int prevMin = mini;
            mini = 2 * mini - curr;
            return prevMin;
        }
    }

    int top() {
        if (s.empty()) {
            return -1; // Stack underflow
        }

        int curr = s.top();
        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if (s.empty()) {
            return -1; // Stack underflow
        }

        return mini;
    }
};

int main() {
    SpecialStack st;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Get Minimum\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                cout << value << " pushed to the stack.\n";
                break;

            case 2:
                value = st.pop();
                if (value == -1) {
                    cout << "Stack is empty! Cannot pop.\n";
                } else {
                    cout << "Popped value: " << value << endl;
                }
                break;

            case 3:
                value = st.top();
                if (value == -1) {
                    cout << "Stack is empty! No top element.\n";
                } else {
                    cout << "Top value: " << value << endl;
                }
                break;

            case 4:
                value = st.getMin();
                if (value == -1) {
                    cout << "Stack is empty! No minimum element.\n";
                } else {
                    cout << "Minimum value: " << value << endl;
                }
                break;

            case 5:
                if (st.isEmpty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}