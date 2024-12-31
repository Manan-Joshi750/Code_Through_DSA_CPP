#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;
   
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == s) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
   
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value you want to achieve: ";
    cin >> target;

    vector<vector<int>> result = pairSum(arr, target);
    cout << "Pairs that add up to the target value are: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")" << endl;
    }
    
    return 0;
}