#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int n, int i) {
    int largest = i;     
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

vector<int> mergeMaxHeaps(vector<int>& heap1, vector<int>& heap2) {
    vector<int> mergedHeap = heap1;
    mergedHeap.insert(mergedHeap.end(), heap2.begin(), heap2.end());

    int n = mergedHeap.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(mergedHeap, n, i);
    }

    return mergedHeap;
}

void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {9, 8, 4, 1};

    vector<int> mergedHeap = mergeMaxHeaps(heap1, heap2);
    cout << "Merged Max Heap : ";
    printHeap(mergedHeap);

    return 0;
}