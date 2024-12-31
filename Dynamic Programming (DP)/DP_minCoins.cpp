/*You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. 
You have to tell the minimum number of elements you have to take to reach the target sum ‘X’. */
#include <bits/stdc++.h>
using namespace std;

int minElementsToReachSum(vector<int>& nums, int x) {
    int n = nums.size();
    vector<int> dp(x + 1, INT_MAX); // dp[i] stores the minimum elements to achieve sum 'i'

    dp[0] = 0; // Base case: 0 elements required to achieve sum 0

    // Iterate through all sums from 1 to x
    for (int i = 1; i <= x; i++) {
        for (int num : nums) {
            if (i >= num && dp[i - num] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x]; // If dp[x] is still INT_MAX, target sum is not achievable
}

int main() {
    vector<int> nums = {1, 3, 4}; // Example array
    int x = 7; // Example target sum
    cout << "Minimum elements needed: " << minElementsToReachSum(nums, x) << endl;
    return 0;
}