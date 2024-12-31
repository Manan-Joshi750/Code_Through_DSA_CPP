#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            // If the character is a closing bracket
            if(ch == ')') {
                bool isRedundant = true;
                
                // Check inside the brackets
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                // Pop the opening bracket '('
                st.pop();
                
                // If no operator was found, brackets are redundant
                if(isRedundant) {
                    return true;
                }
            }
        } 
    }
    
    return false;
}

int main() {
    string s = "((a+b))";
    
    if(findRedundantBrackets(s)) {
        cout << "The expression has redundant brackets." << endl;
    } else {
        cout << "The expression does not have redundant brackets." << endl;
    }
    
    return 0;
}