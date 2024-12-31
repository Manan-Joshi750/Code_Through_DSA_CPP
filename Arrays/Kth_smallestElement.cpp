#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "The " << k << "rd smallest element is " << findKthSmallest(nums, k) << endl;
    return 0;
}