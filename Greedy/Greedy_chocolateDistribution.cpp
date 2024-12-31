/*
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate 
packets among m students such that:
    i. Each student gets exactly one packet.
   ii. The difference between the maximum number of chocolates given to a student and the minimum number of 
       chocolates given to a student is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& arr, int n, int m) {
        if (m == 0 || n == 0) return 0;

        // Sort the array to ensure packets can be selected in contiguous groups
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        // Find the subarray of size `m` with the minimum difference
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};

int main() {
    Solution solution;

    int n, m;
    cout << "Enter the number of packets: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the number of chocolates in each packet: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> m;

    int result = solution.findMinDiff(arr, n, m);
    cout << "Minimum difference is: " << result << endl;

    return 0;
}