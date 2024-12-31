#include <iostream>
#include <string>
using namespace std;

/*We need to replace the spaces in our original string with "@40" and we should provide an in-place solution. 
However we can also make use of another string and whenever we encounter a space in our original string, 
then we push_back @ 4 and 0 one by one to the other string. */
void replaceSpaces(string &s) {
    int spaceCount = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            spaceCount++;
        }
    }

    int newLength = n + spaceCount * 2;  // Each space is replaced by 3 characters
    s.resize(newLength);

    // Modify the string in place from the end
    int j = newLength - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[j] = '0';
            s[j - 1] = '4';
            s[j - 2] = '@';
            j -= 3;
        } else {
            s[j] = s[i];
            j--;
        }
    }
}

int main() {
    string s;
    cout << "Enter any string: ";
    getline(cin, s);  // Use getline to allow spaces in the input

    replaceSpaces(s);

    cout << "String after replacing spaces with @40: " << s << endl;
    return 0;
}