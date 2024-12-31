#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();
    
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
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
    s.push(2);
    s.push(1);
    
    cout << "Original Stack: ";
    printStack(s);
    
    int x = 4;
    s = pushAtBottom(s, x);
    cout << "Stack after pushing " << x << " at the bottom: ";
    printStack(s);
    return 0;
}