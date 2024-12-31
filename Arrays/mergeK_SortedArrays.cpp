#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Custom comparator for the priority queue (min-heap)
    struct compare {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first; // Min-heap based on the array element value
        }
    };

    vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
        // Create a min-heap (priority queue) to store {element, {array_index, element_index}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> minHeap;

        // Push the first element of each array into the heap
        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays[i].empty()) {
                minHeap.push({arrays[i][0], {i, 0}});
            }
        }

        // Result array to store the merged output
        vector<int> result;

        // While the heap is not empty
        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            auto current = minHeap.top();
            minHeap.pop();

            int element = current.first;
            int arrayIndex = current.second.first;
            int elementIndex = current.second.second;

            // Add the smallest element to the result array
            result.push_back(element);

            // If there is a next element in the same array, push it into the heap
            if (elementIndex + 1 < arrays[arrayIndex].size()) {
                minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    Solution sol;
    vector<int> result = sol.mergeKSortedArrays(arrays);

    // Print the merged array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}