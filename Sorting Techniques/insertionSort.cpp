#include<iostream>
#include<vector>
using namespace std;
//Its best case time complexity is O(n) and this would be when the array is already sorted and worst case is O(n^2).
int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    
    if(n<=0){
        cout << "Please enter a valid size for the array : ";
        cin >> n;
    }

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
                                                                //IMPORTANT POINTS
/*An in-place sort is a sorting algorithm that requires only a constant amount of extra space to sort the data. 
This means that the algorithm sorts the data within the original data structure (such as an array or a list) 
and does not require additional storage that grows with the size of the input data.

--> Characteristics of In-Place Sorts :
1. Constant Space : Uses only a small, fixed amount of additional space for variables (typically O(1) extra space).
2. Modifies the Original Data : Sorts the data within the original data structure, modifying the positions of the elements directly.

Examples of In-Place Sorting Algorithms:
1. Bubble Sort : Swaps adjacent elements if they are in the wrong order, iterating through the list multiple times.
2. Insertion Sort : Builds the sorted array one element at a time, inserting each new element into its correct position within the sorted portion.
3. Selection Sort : Repeatedly selects the smallest (or largest) element from the unsorted portion and swaps it with the first unsorted element.
4. Heap Sort : Converts the list into a heap and then repeatedly extracts the maximum element and rebuilds the heap.
5. Quick Sort : Partitions the array into two subarrays around a pivot element, then recursively sorts the subarrays.

Non-In-Place Sorting Algorithms :
1. Merge Sort : Typically requires additional storage proportional to the size of the input data for merging the sorted subarrays.
2. Counting Sort : Requires additional arrays to count the occurrences of each element and to store the sorted output. */