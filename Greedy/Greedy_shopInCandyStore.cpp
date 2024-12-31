/*
In a candy store, there are N different types of candies available, and the prices of all the N different types of candies are provided to you. 
You are now provided with an attractive offer.
For every candy you buy from the store, you get K other candies (all of different types) for free. 

You need to answer two questions:
1. What is the **minimum amount of money** you have to spend to buy all the N different candies?
2. What is the **maximum amount of money** you have to spend to buy all the N different candies?

**Constraints**:
- You must utilize the offer, i.e., for every candy you buy, you get K other candies for free.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> candyStore(vector<int>& prices, int n, int k) {
        // Sort the prices in ascending order
        sort(prices.begin(), prices.end());
        
        // Minimum amount calculation
        int minCost = 0, maxCost = 0;
        int candiesBought = 0;

        // Calculate the minimum cost
        for (int i = 0; i < n; ++i) {
            if (candiesBought >= n) break;
            minCost += prices[i];
            candiesBought += (1 + k);
        }

        // Sort the prices in descending order for maximum cost calculation
        sort(prices.rbegin(), prices.rend());
        candiesBought = 0;

        // Calculate the maximum cost
        for (int i = 0; i < n; ++i) {
            if (candiesBought >= n) break;
            maxCost += prices[i];
            candiesBought += (1 + k);
        }

        return {minCost, maxCost};
    }
};

int main() {
    Solution sol;

    // Input values
    vector<int> prices = {3, 2, 1, 4};
    int n = prices.size();
    int k = 2;

    pair<int, int> result = sol.candyStore(prices, n, k);

    cout << "Minimum cost: " << result.first << endl;
    cout << "Maximum cost: " << result.second << endl;

    return 0;
}