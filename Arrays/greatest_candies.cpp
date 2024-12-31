#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of kids: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid number of kids." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the number of candies the kid is having at index " << i << ": ";
        cin >> arr[i];
    }

    int extraCandies;
    cout << "Enter the number of extra candies you have: ";
    cin >> extraCandies;

    int maxCandies = INT_MIN; // This will denote the maximum number of candies a kid is having.
    for (int i = 0; i < n; i++) {
        maxCandies = max(maxCandies, arr[i]);
    }

    // Creating a boolean array to store the results.
    vector<bool> results(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] + extraCandies >= maxCandies) {
            results[i] = true;
        } else {
            results[i] = false;
        }
    }

    cout << "The boolean array is: ";
    for (int i = 0; i < n; i++) {
        if (results[i]) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    cout << endl;
    return 0;
}