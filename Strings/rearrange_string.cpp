#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string rearrangeString(string S) {
        unordered_map<char, int> freq;
        
        // Count the frequency of each character
        for (char ch : S) {
            freq[ch]++;
        }

        // Max-heap (priority queue) to store characters by their frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            maxHeap.push({it->second, it->first});
        }

        string result;
        pair<int, char> prev = {-1, '#'}; // Previous character to compare

        // Rebuild the string by always choosing the most frequent character
        while (!maxHeap.empty()) {
            pair<int, char> current = maxHeap.top();
            maxHeap.pop();
            
            // Append current character to the result
            result += current.second;

            // If the previous character still has a remaining count, push it back into the heap
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            // Update prev to the current character with its count reduced by 1
            prev = {current.first - 1, current.second};
        }

        // If the result length matches original, it is valid; otherwise, impossible
        return result.size() == S.size() ? result : "not possible";
    }
};

int main() {
    int T;
    cin >> T;
    Solution solution;

    while (T--) {
        string S;
        cin >> S;
        string rearranged = solution.rearrangeString(S);
        if (rearranged != "not possible") {
            cout << "Yes\n" << rearranged << endl;
        } else {
            cout << "not possible" << endl;
        }
    }

    return 0;
}