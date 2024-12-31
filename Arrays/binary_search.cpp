#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int value){
    int left = 0, right = n-1;
    int mid = left + (right - left)/2; // not writing mid = (left + right)/2 because this could lead to a value getting out of an integer's range.

    while(left <= right){
        if(arr[mid] == value){
            return mid;
        } else if(arr[mid] < value){
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        mid = left + (right - left)/2;
    }
    return -1;
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

    int value;
    cout << "Enter the value to search : ";
    cin >> value;

    if(binarySearch(arr,n,value) != -1){
        cout << "The Number " << value << " is found in the array at index " << binarySearch(arr,n,value);
    } else {
        cout << "The Number " << value << " is not found in the array";
    }
    return 0;
}