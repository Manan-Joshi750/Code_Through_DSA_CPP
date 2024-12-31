#include <iostream>
#include <stack>
#include <string>
using namespace std;
//BALANCED PARENTHESIS.
bool isBalanced(const string& expression) {
    stack<char> parentheses;

    for (char bracket : expression) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            parentheses.push(bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (parentheses.empty() || 
               (bracket == ')' && parentheses.top() != '(') || 
               (bracket == ']' && parentheses.top() != '[') || 
               (bracket == '}' && parentheses.top() != '{')) {
                return false;
            }
            parentheses.pop();
        }
    }
    return parentheses.empty();
}

int main() {
    string expression;
    cout << "Enter an expression with parentheses: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The parentheses in the expression are balanced." << endl;
    } else {
        cout << "The parentheses in the expression are not balanced." << endl;
    }
    return 0;
}
