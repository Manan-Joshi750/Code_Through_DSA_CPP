#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {
    if(count == size / 2) {
        inputStack.pop(); 
        return;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    solve(inputStack, count + 1, size);
    inputStack.push(num);
}

// Function to delete the middle element of the stack
void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    cout << "Original Stack: ";
    printStack(s);

    int size = s.size();
    deleteMiddle(s, size);
    cout << "Stack after deleting middle element: ";
    printStack(s);
    return 0;
}