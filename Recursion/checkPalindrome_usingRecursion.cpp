#include<iostream>
using namespace std;
//This function makes use of two pointers.
bool checkPalindrome1(string str, int start, int end){
    if(start > end){
        return true;
    }

    if(str[start] != str[end]){
        return false;
    } else {
        return checkPalindrome1(str, start + 1, end - 1);
    }
}

//And this one makes use of only one.
bool checkPalindrome2(string str, int start){
    if(start > str.length()){
        return true;
    }

    if(str[start] != str[str.length() - start - 1]){
        return false;
    } else {
        return checkPalindrome2(str, start + 1);
    }
}

int main(){
    string str;
    cout << "Enter any string (WITHOUT ANY WHITESPACE AND ALL) : ";
    cin >> str;

    int start = 0;
    int end = str.length() - 1;
    bool isPalindrome1 = checkPalindrome1(str, start, end);

    if(isPalindrome1){
        cout << "The string " << str << " is a palindrome" << endl;
    } else {
        cout << "The string " << str << " is NOT a palindrome" << endl;
    }

    bool isPalindrome2 = checkPalindrome2(str, start);
    cout << "   .....CHECKING AGAIN.....      " << endl;
    if(isPalindrome2){
        cout << "The string " << str << " is a palindrome" << endl;
    } else {
        cout << "The string " << str << " is NOT a palindrome" << endl;
    }

    return 0;
}