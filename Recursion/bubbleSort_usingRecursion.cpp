#include<iostream>
using namespace std;

void sortArray(int arr[], int n){
    if(n == 0 || n == 1){
        return;
    }

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    sortArray(arr, n-1);
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    sortArray(arr, n);
    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    delete []arr;
    return 0;
}