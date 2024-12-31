#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//SLIDING WINDOW MAXIMUM PROBLEM.
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements outside the window's range
        if (!window.empty() && window.front() == i - k)
            window.pop_front();
        // Remove smaller elements from the back of the deque
        while (!window.empty() && nums[i] > nums[window.back()])
            window.pop_back();

        window.push_back(i);
        // Once the window size reaches 'k', store the maximum element
        if (i >= k - 1)
            result.push_back(nums[window.front()]);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7}; // Example input array
    int k = 3; // Window size

    vector<int> result = maxSlidingWindow(nums, k);
    cout << "Maximum elements in sliding windows of size " << k << " are:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
