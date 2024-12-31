#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1 < n){
            swap(arr[i], arr[i+1]);
        }
    }

    cout << "Modified array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
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

    swapAlternate(arr,n);
    return 0;
}