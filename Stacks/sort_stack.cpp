#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    if(stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    
    int num = stack.top();
    stack.pop();
    
    sortStack(stack);
    sortedInsert(stack, num);
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
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(5);
    
    cout << "Original Stack: ";
    printStack(s);
    
    sortStack(s);
    cout << "Sorted Stack: ";
    printStack(s);
    return 0;
}