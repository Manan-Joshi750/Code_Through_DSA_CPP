//TWO SUM Problem(that is, we need to return the index of those two elements whose sum equals to target(given by the user)).
#include<iostream>
using namespace std;

void twoSum(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Indices are : " << i << " and " << j;
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout << "No two numbers found that add up to the target.";
    }
}

int main(){
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum you want to achieve : ";
    cin >> target;

    twoSum(arr, size, target);
    return 0;
}