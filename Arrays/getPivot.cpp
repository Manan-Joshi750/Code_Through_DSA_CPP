#include<iostream>
using namespace std;
//The array to be passed over here would be a rotated sorted array.
int getPivot(int arr[], int n){
    int left = 0, right = n-1;
    int mid = left + (right - left)/2;

    while(left < right){
        if(arr[mid] >= arr[0]){
            left = mid + 1;
        } else {
            right = mid;
        }
        mid = left + (right - left)/2;
    }

    return left;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin>> arr[i];
    }

    cout << "Pivot element in the given array is at index : " << getPivot(arr, n);
    return 0;
}