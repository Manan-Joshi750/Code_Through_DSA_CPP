#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargestSumSubarray(vector<int>& arr, int k) {
    // Min-heap to store the top k largest sums
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int n = arr.size();
    
    // Generate all possible subarray sums
    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        
        // Subarray starting from index i
        for (int j = i; j < n; ++j) {
            // Calculate sum of subarray arr[i...j]
            currentSum += arr[j];
            
            // If heap has less than k elements, push the sum
            if (minHeap.size() < k) {
                minHeap.push(currentSum);
            }
            // If the current sum is larger than the smallest in the heap
            else if (currentSum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(currentSum);
            }
        }
    }
    
    // The root of the heap is the k-th largest sum
    return minHeap.top();
}

int main() {
    vector<int> arr = {10, -10, 20, -40, 30};
    
    int k = 3;
    int result = kthLargestSumSubarray(arr, k);
    cout << "The " << k << "-th largest sum subarray is: " << result << endl;
    
    return 0;
}