#include<iostream>
#include<algorithm>
using namespace std;

void sortArray(int arr[], int n){
    int left = 0, right = n-1;

    while(left < right){
        while(arr[left] == 0 && left < right){
            left++;
        }
        while(arr[right] == 1 && left < right){
            right--;
        }

        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    cout << "Sorted Array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of the array containing ONLY 0's and 1's : ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin>> arr[i];
    }

    sortArray(arr, n);
    return 0;
}