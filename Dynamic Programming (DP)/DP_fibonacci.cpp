/*There are 2 approaches in DP : 
1. Top-Down approach : recursion + memoization (store the values of subproblems in map/tables)
2. Bottom-up approach : tabulation 
And then comes space efficiency. */
#include<iostream>
#include<vector>
using namespace std;

//top-down approach : TC was O(n) and SC was O(n) + O(n)
int fib(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    cout << "Enter the value number you want to find : ";
    cin >> n;

    vector<int> dp1(n+1);
    for(int i=0; i<=n; i++){
        dp1[i] = -1;
    }

    cout << "Top-down approach value is : " << fib(n, dp1) << endl;

    //bottom-up approach : TC was O(n) and SC was O(n)
    vector<int> dp2(n+1);
    dp2[1] = 1;
    dp2[0] = 0;

    for(int i=2; i<=n; i++){
        dp2[i] = dp2[i-1] + dp2[i-2];
    }

    cout << "Bottom-up approach value is : " << dp2[n] << endl;

    //space efficieny : TC was O(n) and SC was O(1)
    int prev1 = 1, prev2 = 0;
    if(n == 0) return prev2;

    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << "Space efficiency value is : " << prev1 << endl;
    return 0;
}