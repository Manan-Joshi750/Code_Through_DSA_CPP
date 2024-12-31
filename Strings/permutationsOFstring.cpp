#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string str, vector<string> &ans, int index) {
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++) {
        // Skip duplicates
        if (j != index && str[j] == str[index]) {
            continue;
        }
        swap(str[index], str[j]);
        solve(str, ans, index + 1);
        // Backtracking
        swap(str[index], str[j]);
    }
}

vector<string> permute(string str) {
    vector<string> ans;
    sort(str.begin(), str.end());
    solve(str, ans, 0);
    return ans;
}

int main() {
    string str;
    cout << "Enter any string: ";
    cin >> str;

    vector<string> result = permute(str);

    cout << "All possible unique permutations are: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}