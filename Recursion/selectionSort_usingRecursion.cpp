#include <iostream>
using namespace std;

// Helper function to find the index of the minimum element in the subarray [start, end]
int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSortRecursive(int arr[], int start, int n) {
    if (start >= n - 1) {
        return;
    }

    int minIndex = findMinIndex(arr, start, n - 1);
    swap(arr[start], arr[minIndex]);

    selectionSortRecursive(arr, start + 1, n);
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

    selectionSortRecursive(arr, 0, n);

    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}