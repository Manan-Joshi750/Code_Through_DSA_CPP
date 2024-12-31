#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cout << "Enter any string : ";
    cin >> str;

    stack<char> s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string reverse = "";
    while(!s.empty()){
        reverse += s.top();
        s.pop();
    }

    cout << "Reversed string is : " << reverse << endl;
    return 0;
}