/*Heap is a data structure which is a complete binary tree that comes with a heap order property. CBT is a binary tree where every level is completely 
filled except the last level and nodes are always added from the left or we can say nodes lean towards the left. 

There are two types of heaps : Max Heap and Min Heap and this is what heap order property means. 
Max Heap means if there is a node in a tree, then its value would be greater than its child nodes value and Min Heap means if there is a node in a tree, 
then its value would be smaller than that of its child node values. 

IMPORTANT : Now we will be seeing the heap implementation using arrays. So if our node is present on i'th index, then its left child would be present on the
(2*i)'th index and right child on the (2*i + 1)'th index and parent node on the (i/2)'th index. This is the case when we are having 1 based indexing
and when we have 0 based indexing, then left child would be present on the (2*i + 1)'th index and right child on the (2*i + 2)'th index.

IMPORTANT : If size of our array is n, then leaf nodes of a CBT lies from (n/2 + 1)'th index to n'th index. And this means that if we are processing the nodes
from index 1 to index n, then we dont have to process the nodes from (n/2 + 1)'th index to n'th index because they are leaf nodes and so, they are
already at their correct places as leaf nodes are itself considered as heaps. 
In HEAPIFY ALGORITHM, the work of heapify function is to place a node at its correct position. */

#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    //Time complexity of this insertion function is O(logn) as we are comparing every node with its parent which is present at index i/2 if node's index is i. 
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;
            //This logic is applied when we are dealing with the case of a Max Heap. 
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }

    /*Time complexity of this deletion operation is also O(logn). 
    And whenever we are talking about deletion, then it means we are talking about the deletion of the root node. */
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete....." << endl;
            return;
        }

        arr[1] = arr[size]; // copy last node to the first node
        size--;

        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};

//This is our heapify algorithm. 
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    //left <= n and right <= n are written because here we are dealing with 1 based indexing. If we have 0 based indexing, then left < n and right < n. 
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//Time complexity of heap sort is O(nlogn). 
void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i= n/2; i>0; i--){
        heapify(arr, n, i); //This line or basically creation of a heap takes O(n) time complexity. 
    }

    cout << "Printing the array now : ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, n);
    cout << "Printing the sorted array now : ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}