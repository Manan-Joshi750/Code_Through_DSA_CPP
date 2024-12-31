#include<iostream>
#include<vector>
using namespace std;
//This sorting technique is good/accurate for small sized arrays/vectors/lists.
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

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

                                                                    //IMPORTANT NOTES : 
/*An algorithm's stability is determined by how it handles equal elements during the sorting process. Specifically:

1. Stable Sorting Algorithm :
A sorting algorithm is stable if it preserves the relative order of equal elements in the input data. 
In other words, if two elements are equal, a stable sort ensures that their order relative to each other remains the same 
in the sorted output as it was in the input.

2. Unstable Sorting Algorithm : 
A sorting algorithm is unstable if it does not necessarily preserve the relative order of equal elements. 
That means equal elements might end up in a different order in the sorted output compared to their order in the input.

3. Examples of Stable Sorting Algorithms : 
Bubble Sort, Insertion Sort, Merge Sort, Counting Sort, Tim Sort (used in Python’s sorted() function and Java’s Arrays.sort() for non-primitives).

4. Examples of Unstable Sorting Algorithms : 
Quick Sort (in most implementations), Heap Sort, Selection Sort.

5. Why Stability Matters : 
--> Preserving Information: When sorting a list of objects based on one key while needing to preserve the relative order of another key, stability is essential.
--> Multi-level Sorting: Stability is useful when you perform multiple sorts on the same data. 
For example, sorting by last name and then by first name can benefit from a stable sort to maintain the initial order of equal elements after the first sort.

6. Example to Illustrate Stability : 
Consider the following list of tuples where each tuple represents a student (ID, Score):

[(1, 95), (2, 85), (3, 95), (4, 75)]
If we sort this list by the second element (Score):

--> Stable Sort : [(4, 75), (2, 85), (1, 95), (3, 95)]
The relative order of the two students with a score of 95 (ID 1 and ID 3) is preserved.
--> Unstable Sort : [(4, 75), (2, 85), (3, 95), (1, 95)]
The relative order of the two students with a score of 95 is not preserved.

7. Implementation Considerations : 
When implementing or choosing a sorting algorithm, consider whether stability is important for your specific application.
If the relative order of equal elements needs to be maintained, you should choose or implement a stable sorting algorithm. */