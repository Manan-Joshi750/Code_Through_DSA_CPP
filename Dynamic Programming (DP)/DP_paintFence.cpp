/*Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. 
Ninja wants to paint the fence so that not more than two adjacent posts have the same color.
Ninja wonders how many ways are there to do the above task, so he asked for your help.
Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7. */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        const int MOD = 1e9 + 7;

        if (n == 1) return k;
        if (n == 2) return (k + (long long)k * (k - 1)) % MOD;

        long long same = k; // Number of ways to paint first two posts with the same color
        long long diff = (long long)k * (k - 1) % MOD; // Number of ways to paint first two posts with different colors
        long long total = (same + diff) % MOD;

        for (int i = 3; i <= n; i++) {
            same = diff; // The same color for current post comes from diff of previous
            diff = total * (k - 1) % MOD; // Different color for current post
            total = (same + diff) % MOD; // Total ways to paint up to current post
        }

        return total;
    }
};

int main() {
    Solution solution;
    int n = 5, k = 3; // Example: 5 posts, 3 colors
    cout << solution.numWays(n, k) << endl;
    return 0;
}