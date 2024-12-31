/*
Given a string s, reverse the string without reversing its individual words. Words are separated by spaces.
Note:
1. The string may contain leading or trailing spaces, or multiple spaces between two words.
2. The returned string should only have a single space separating the words, and no extra spaces should be included.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        // Split the string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words with a single space
        string result = "";
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }

        return result;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter the string: ";
    getline(cin, input);

    string result = solution.reverseWords(input);
    cout << "Reversed string: " << result << endl;

    return 0;
}