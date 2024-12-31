/*You are given an array/list of ‘N’ integers. 
You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, 
leaving the remaining elements in their original order. */
#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Variables to store results for i+1 and i+2
    int prev2 = 0; // dp[i+2]
    int prev1 = nums[0]; // dp[i+1] for the first element

    for (int i = 1; i < n; i++) {
        int include = nums[i] + prev2; // Include the current element
        int exclude = prev1;          // Exclude the current element

        int curr = max(include, exclude); // Current dp[i]
        prev2 = prev1; // Update dp[i+2]
        prev1 = curr;  // Update dp[i+1]
    }

    return prev1; // Final result
}

int main() {
    vector<int> nums = {3, 2, 5, 10, 7};
    cout << "Maximum Non-Adjacent Sum: " << maximumNonAdjacentSum(nums) << endl;
    return 0;
}