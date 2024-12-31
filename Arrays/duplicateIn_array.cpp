#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i]; 
    }

    for(int i=1; i<n; i++){
        ans = ans ^ i; 
    }

    return ans;
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

    cout << "Duplicate element in the array is : " << findDuplicate(arr, n);
    return 0;
}