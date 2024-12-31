#include<iostream>
using namespace std;

void merge(int arr[], int start, int end){
    int mid = start + (end - start)/2;

    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *first = new int[length1];
    int *second = new int[length2];

    int mainArrayIndex = start;
    for(int i=0; i<length1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i=0; i<length2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < length1 && index2 < length2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < length1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < length2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

//This we can use to track the portion of the array which is being passed while recursive calls.
// void printArray(int arr[], int start, int end){
//     for(int i=start; i<=end; i++){
//         cout << arr[i] << " ";
//     } cout << endl;
// }

void mergeSort(int arr[], int start, int end){
    // printArray(arr, start, end);
    if(start >= end){
        return;
    }

    int mid = start + (end - start)/2;
    //Sort left part of array
    mergeSort(arr, start, mid);

    //Sort right part of array
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
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

    mergeSort(arr, 0, n-1);
    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    delete []arr;
    return 0;
}