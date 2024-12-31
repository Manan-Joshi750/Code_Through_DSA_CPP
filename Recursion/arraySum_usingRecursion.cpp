#include<iostream>
using namespace std;

int arraySum(int arr[], int n){
    if(n == 0) {
        return 0;
    }
    if(n == 1 )
    {
        return arr[0];
    }

    int remainingPart = arraySum(arr + 1, n - 1);
    int currentSum = arr[0] + remainingPart;
    return currentSum;
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

    int sum = arraySum(arr, n);
    cout << "Sum of all elements of the array is : " << sum;

    delete []arr;
    return 0;
}