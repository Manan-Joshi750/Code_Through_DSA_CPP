/*A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, 
you have to find and return the maximum value that a thief can generate by stealing items. */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Standard 2D DP solution
    int knapsack2D(int W, vector<int>& weights, vector<int>& values, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                if (weights[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j]; // Exclude the item
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]); // Include or exclude
                }
            }
        }

        return dp[N][W]; // Maximum value with N items and capacity W
    }

    // Space-optimized 1D DP solution
    int knapsack1D(int W, vector<int>& weights, vector<int>& values, int N) {
        vector<int> dp(W + 1, 0);

        // Fill the DP array
        for (int i = 0; i < N; i++) {
            for (int j = W; j >= weights[i]; j--) {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }

        return dp[W]; // Maximum value with capacity W
    }
};

int main() {
    Solution solution;
    int W = 50; // Maximum weight capacity
    vector<int> weights = {10, 20, 30}; // Weights of the items
    vector<int> values = {60, 100, 120}; // Values of the items
    int N = weights.size();

    // Solve using 2D DP
    cout << "2D DP Solution: Maximum value = " << solution.knapsack2D(W, weights, values, N) << endl;

    // Solve using 1D DP
    cout << "1D DP Solution: Maximum value = " << solution.knapsack1D(W, weights, values, N) << endl;

    return 0;
}