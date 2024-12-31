#include <bits/stdc++.h>
using namespace std;

// Function to find the first negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Process the first window of size K
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    // Add the result for the first window
    if(!dq.empty()) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the remaining windows
    for(int i = K; i < N; i++) {
        // Remove elements that are out of this window
        if(!dq.empty() && (i - dq.front()) >= K) {
            dq.pop_front();
        }

        // Add the current element if it's negative
        if(A[i] < 0) {
            dq.push_back(i);
        }

        // Add the result for the current window
        if(!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    long long int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        long long int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        long long int arr[n];
        cout << "Enter the elements of the array: ";
        for (long long int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long int k;
        cout << "Enter the size of the window: ";
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        cout << "First negative integer in every window of size " << k << ": ";
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    return 0;
}