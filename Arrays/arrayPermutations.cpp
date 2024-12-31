// #include <iostream>
// #include <vector>
// using namespace std;
// //All possible permutations of an array in any order (ALL ELEMENTS OF THE ARRAY ARE DISTINCT).
// void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
//     if (start == nums.size() - 1) {
//         result.push_back(nums);
//         return;
//     }

//     for (int i = start; i < nums.size(); ++i) {
//         swap(nums[start], nums[i]);
//         generatePermutations(nums, start + 1, result);
//         swap(nums[start], nums[i]);
//     }
// }
// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> result;
//     generatePermutations(nums, 0, result);
//     return result;
// }

// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;

//     vector<int> nums(size);
//     cout << "Enter " << size << " distinct integers for the array: ";
//     for (int i = 0; i < size; ++i) {
//         cin >> nums[i];
//     }

//     vector<vector<int>> permutations = permute(nums);
//     cout << "All possible permutations:" << endl;
//     for (const auto& perm : permutations) {
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//STL trick to do the same as done above(ALL ELEMENTS OF THE ARRAY ARE DISTINCT).
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter " << size << " distinct integers for the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // Sort the array to generate permutations
    cout << "All possible permutations:" << endl;
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
