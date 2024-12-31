#include<iostream>
using namespace std;

char getMaxChar(string s){
    int arr[26]  = {0};

    //Create an array of count of characters.
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occuring character.
    int maxVal = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(maxVal < arr[i]){
            ans = i;
            maxVal = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
} 

int main(){
    string s;
    cout << "Enter any string : ";
    cin >> s;

    cout << "Maximum Occurring character in the string " << s << " is : " << getMaxChar(s);
    return 0;
}