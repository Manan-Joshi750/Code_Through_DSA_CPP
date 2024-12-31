#include <iostream>
using namespace std;

// Recursive function to insert the element at the nth position into its correct position in the sorted subarray [0, n-1]
void insert(int arr[], int n) {
    if (n <= 0) {
        return;
    }

    // Sort the first n-1 elements
    insert(arr, n - 1);

    int last = arr[n];
    int j = n - 1;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert the nth element into its correct position in the sorted subarray
    insert(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    insertionSortRecursive(arr, n);

    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}