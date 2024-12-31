#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Printing all possible words from phone digits.
const vector<string> keypad = {     // Mapping of digits to corresponding letters on a phone keypad.
    "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};
// Recursive function to generate combinations of letters from digits.
void generateWordsUtil(const string& digits, int current, string& result, vector<string>& combinations) {
    if (current == digits.length()) {
        combinations.push_back(result);
        return;
    }

    int digit = digits[current] - '0';
    const string& letters = keypad[digit];

    for (char letter : letters) {
        result[current] = letter;
        generateWordsUtil(digits, current + 1, result, combinations);
    }
}
// Function to generate all possible combinations of letters from digits
vector<string> generateWords(const string& digits) {
    vector<string> combinations;
    if (digits.empty()) return combinations;

    string result(digits.length(), ' ');

    generateWordsUtil(digits, 0, result, combinations);

    return combinations;
}
int main() {
    string digits;
    cout << "Enter the digits (0-9): ";
    cin >> digits;

    vector<string> words = generateWords(digits);

    cout << "Possible words from the digits '" << digits << "':" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
