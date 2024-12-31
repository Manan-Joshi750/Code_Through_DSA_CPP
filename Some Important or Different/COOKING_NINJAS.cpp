/*In Ninja Land, there is a famous restaurant named ‘CookingNinjas’.
There are ‘N’ cooks in ‘CookingNinjas’ numbered from 0 to N-1. Each cook has rank ‘R’ (1 <= R <= 10).
A cook with a rank ‘R’ can prepare 1 dish in the first ‘R’ minutes, 1 more dish in the next ‘2R’ minutes, 
1 more dish in next ‘3R’ minutes, and so on (A cook can only make complete dishes). For example if a cook is ranked 2,
He will prepare one dish in 2 minutes, one more dish in the next 4 mins and one more in the next 6 minutes hence in a total of 12 minutes he can make 3 dishes.

NOTE : 
In 13 minutes also he can make only 3 dishes as he does not have enough time for the 4th dish).
One day ‘CookingNinjas’ receive an order of ‘M’ dishes that they need to complete as early as possible. 
You are given an integer array ‘rank’ of size ‘N’ in which ‘rank[i]’ gives ‘rank’ of ith cook and an integer ‘M’.
You need to find out the minimum times required to complete this order of ’M’ dishes.

NOTE :
One dish can be prepared by only one cook, however, two or more cooks can simultaneously prepare different dishes. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& ranks, int n, int m, int mid) {
    int totalDishes = 0;
    for (int i = 0; i < n; i++) {
        int time = mid;
        int count = 0;
        int r = ranks[i];
        while (time >= (count + 1) * r) {
            count++;
            time -= count * r;
        }
        totalDishes += count;
        if (totalDishes >= m) {
            return true;
        }
    }
    return false;
}

int minTime(vector<int>& ranks, int n, int m) {
    sort(ranks.begin(), ranks.end()); // Sort ranks to ensure we start with the least time

    int start = 0;
    int end = ranks[0] * (m * (m + 1)) / 2;
    int ans = end;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(ranks, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cooks : ";
    cin >> n;

    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the rank of cook " << i << " : ";
        cin >> ranks[i];
    }

    int m;
    cout << "Enter the number of dishes to be prepared : ";
    cin >> m;

    cout << "Minimum time required to prepare " << m << " dishes is : " << minTime(ranks, n, m) << " minutes." << endl;
    return 0;
}