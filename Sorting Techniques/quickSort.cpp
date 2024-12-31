#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];

    int smallNums_ThanPivot_count = 0;
    for(int i= start+1; i<=end; i++){
        if(arr[i] <= pivot){
            smallNums_ThanPivot_count++;
        }
    }

    //Place the pivot at right position
    int pivotIndex = start + smallNums_ThanPivot_count;
    swap(arr[pivotIndex], arr[start]);

    //Now we will be making sure that the left part of array is less than the pivot value and right part gretaer than the pivot value.
    int left = start, right = end;
    while(left < pivotIndex && right > pivotIndex){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }

        if(left < pivotIndex && right > pivotIndex){
            swap(arr[left++], arr[right--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    int p = partition(arr, start, end);

    //Sort left part of array
    quickSort(arr, start, p - 1);

    //Sort right part of array
    quickSort(arr, p + 1, end);
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

    quickSort(arr, 0, n-1);
    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    delete []arr;
    return 0;
}