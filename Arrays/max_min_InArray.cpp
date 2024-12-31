#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    for(int i=0; i<size; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    for(int i=0; i<size; i++){
        maxNum = max(maxNum, arr[i]);
        minNum = min(minNum, arr[i]);
    }

    cout << "Maximum and Minimum numbers in the array are : " << maxNum << " and " << minNum << " respectively";
    return 0;
}