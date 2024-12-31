#include <iostream>
#include <stack>
#include <string>
using namespace std;

int findMinimumCost(string str) {
    // If the length of the string is odd, it's impossible to balance it. 
    if(str.length() % 2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i = 0; i < str.length(); i++) { 
        char ch = str[i];
        
        if(ch == '{') {
            s.push(ch);
        } else {
            // If there's a corresponding opening brace, pop it
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            // Otherwise, push the closing brace onto the stack
            else {
                s.push(ch);
            }
        }
    }
    
    // After processing, the stack contains the unbalanced parts
    int a = 0, b = 0;
    
    while(!s.empty()) {
        if(s.top() == '{') {
            b++;
        } else {
            a++;
        }
        s.pop();
    }
    
    // To balance, we need to reverse half of each set of unbalanced braces
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string str = "{{{{}}";
    int result = findMinimumCost(str);
    
    if(result == -1) {
        cout << "The string cannot be balanced." << endl;
    } else {
        cout << "Minimum number of reversals needed: " << result << endl;
    }
    
    return 0;
}