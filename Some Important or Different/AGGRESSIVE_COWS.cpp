/*You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows so that they don't fight with each other but in a way
such that the minimum distance between any two of them is the maximum possible.
Print the maximum possible minimum distance. */
#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {
    int cowCount = 1;
    int lastPosition = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPosition >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPosition = arr[i];
        }
    }
    return false;
}

int aggressiveCows(int arr[], int n, int k) {
    sort(arr, arr + n);

    int start = 0;
    int stallMaxValue = arr[n - 1];
    int end = stallMaxValue;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the position of stall at index " << i << " : ";
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of aggressive cows you need to place : ";
    cin >> k;

    cout << "Maximum possible minimum distance is : " << aggressiveCows(arr, n, k);
    return 0;
}