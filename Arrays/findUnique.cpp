/*In this question, we would be a given an array of size n where n = 2m + 1 where m represents the number of times each value is present
in the array except that one value which is appearing only 1 time in the array and we have to return this value.*/
#include<iostream>
using namespace std;

int findUnique(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i]; //XOR of a number with the number itself gives 0 and XOR of 0 with any value gives that value itself.
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

    cout << "Unique element in the array is : " << findUnique(arr, n);
    return 0;
}