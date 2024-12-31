#include<iostream>
using namespace std;
/*We have written string &str so that the changes get reflected in the original string otherise they would be reflected in a copy of string which wouldn't
accessible outside the function. */
void reverseString(string &str, int start, int end){
    if(start > end){
        return;
    }

    swap(str[start], str[end]);
    start++;
    end--;

    reverseString(str, start, end);
}

int main(){
    string str;
    cout << "Enter any string (WITHOUT ANY WHITESPACE AND ALL) : ";
    cin >> str;

    cout << "Reversed form of " << str << " is : ";
    int start = 0;
    int end = str.length() - 1;
    reverseString(str, start, end);

    cout << str;
    return 0;
}