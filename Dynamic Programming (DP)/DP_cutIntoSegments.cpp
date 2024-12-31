/*You are given an integer ‘N’ denoting the length of the rod. 
You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'. */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSegments(int N, int X, int Y, int Z) {
        vector<int> dp(N + 1, -1);
        dp[0] = 0; // Base case: no length means 0 segments

        for (int i = 1; i <= N; i++) {
            if (i >= X && dp[i - X] != -1) dp[i] = max(dp[i], dp[i - X] + 1);
            if (i >= Y && dp[i - Y] != -1) dp[i] = max(dp[i], dp[i - Y] + 1);
            if (i >= Z && dp[i - Z] != -1) dp[i] = max(dp[i], dp[i - Z] + 1);
        }

        return dp[N] == -1 ? 0 : dp[N]; // If dp[N] is still -1, no segments can be formed
    }
};

int main() {
    Solution sol;
    int N = 7, X = 2, Y = 3, Z = 4;
    cout << sol.maximizeSegments(N, X, Y, Z) << endl;
    return 0;
}