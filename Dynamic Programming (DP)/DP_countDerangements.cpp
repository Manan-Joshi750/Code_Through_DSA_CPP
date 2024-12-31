/*A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. 
For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 
and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
Note:
The answer could be very large, output answer %(10 ^ 9 + 7). */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDerangement(int n, bool useOptimized = true) {
        const int MOD = 1e9 + 7;

        if (n == 0) return 1; // D(0) = 1
        if (n == 1) return 0; // D(1) = 0

        if (useOptimized) {
            // Space-Optimized Approach
            long long prev2 = 1; // D(0)
            long long prev1 = 0; // D(1)
            long long curr;

            for (int i = 2; i <= n; i++) {
                curr = ((i - 1) * (prev1 + prev2)) % MOD;
                prev2 = prev1;
                prev1 = curr;
            }

            return curr;
        } else {
            // Regular DP Approach
            vector<int> dp(n + 1, 0);
            dp[0] = 1; // Base case
            dp[1] = 0; // Base case

            for (int i = 2; i <= n; i++) {
                dp[i] = ((long long)(i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
            }

            return dp[n];
        }
    }
};

int main() {
    Solution sol;
    int n = 4; 
    cout << "Using Optimized Approach: " << sol.findDerangement(n, true) << endl;
    cout << "Using Regular DP Approach: " << sol.findDerangement(n, false) << endl;

    return 0;
}