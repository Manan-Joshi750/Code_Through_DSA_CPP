/*
Geekina got stuck on an island. There is only one shop on this island, and it is open on all days of the week except for Sunday. 
Consider the following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.

Currently, it’s Monday, and she needs to survive for the next S days. 
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, 
or determine that it isn’t possible to survive.

Constraints:
1. The shop is closed on Sundays.
2. For every day, you can only buy up to N units of food.
3. You need M units of food every day to survive.

Input:
S: Number of days to survive
N: Maximum food you can buy per day
M: Units of food needed per day to survive

Output:
Return the minimum number of days required to buy food to survive, or -1 if it's not possible to survive.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDays(int S, int N, int M) {
        // Total food required
        int total_food = S * M;

        // Total days the shop is open
        int available_days = S - (S / 7);

        // Check if survival is possible
        if (M > N || total_food > available_days * N) {
            return -1;
        }

        // Calculate the minimum buying days
        int buying_days = (total_food + N - 1) / N; // Equivalent to ceil(total_food / N)

        return buying_days;
    }
};

int main() {
    Solution solution;
    int S, N, M;
    cout << "Enter the number of days to survive (S): ";
    cin >> S;
    cout << "Enter the maximum food you can buy per day (N): ";
    cin >> N;
    cout << "Enter the food needed per day to survive (M): ";
    cin >> M;

    int result = solution.minimumDays(S, N, M);
    if (result == -1) {
        cout << "It is not possible to survive.\n";
    } else {
        cout << "Minimum days needed to buy food: " << result << endl;
    }

    return 0;
}