#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key){
    if(start > end){
        return false;
    }

    int mid = start + (end - start)/2;
    if(arr[mid] == key){
        return true;
    } else if(arr[mid] < key){
        return binarySearch(arr, mid + 1, end, key);
    } else {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    //We know array should be sorted for implementing binary search. 
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    int key;
    cout << "Enter the value of key to search : ";
    cin >> key;

    bool ans = binarySearch(arr, 0, n-1, key);
    if(ans){
        cout << key << " is present in the array";
    } else {
        cout << key << " is not present in the array";
    }

    delete []arr;
    return 0;
}