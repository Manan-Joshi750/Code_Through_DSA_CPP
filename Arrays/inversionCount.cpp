#include <iostream>
using namespace std;
//Given an array of integers. Find the Inversion Count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Function to count inversions without using merge sort
int getInvCount(int arr[], int n) {
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

// Function to merge two subarrays and count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    int inv_count = 0;

    // Merge the two halves
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i); // Number of elements remaining in the left subarray
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray, if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the merged elements back to the original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Function to use merge sort and count inversions
int _mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        // Count inversions in left and right halves and merge them
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two halves and count inversions
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Function to initialize temporary array and call _mergeSort
int mergeSort(int arr[], int array_size) {
    int* temp = new int[array_size];
    int inv_count = _mergeSort(arr, temp, 0, array_size - 1);
    delete[] temp;
    return inv_count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    cout << "Number of inversions without using merge sort: " << getInvCount(arr, n) << endl;
    cout << "Number of inversions using merge sort: " << mergeSort(arr, n) << endl;

    delete[] arr;
    return 0;
}