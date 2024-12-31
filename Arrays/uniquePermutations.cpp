#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to find unique permutations
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    // Sort the numbers to handle duplicates
    sort(nums.begin(), nums.end());
    
    do {
        result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    
    return result;
}

int main() {
    int size;
    cout << "Enter the size of the collection: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the elements of the collection:\n";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> permutations = permuteUnique(nums);
    cout << "Unique Permutations:" << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
