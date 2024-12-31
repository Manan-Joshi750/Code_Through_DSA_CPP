#include<iostream>
#include<vector>
using namespace std;
//In bubble sort, the ith largest element gets placed in its correct position in the ith round.
//Its best time complexity is O(n) and this will be acheived when we are having a check with that variable "swapped".
//But without that, its time complexity would be O(n^2). And bubble sort is applicable for different data types as well.
/*After each pass, the largest element among the unsorted elements "bubbles up" to the last position of the current unsorted portion of the array. 
This means that with each pass, the largest unsorted element is moved to its correct sorted position at the end of the array.*/
//Its main drawback is that it has high time complexity. 
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

    for (int i = 0; i < n-1; i++) {
        bool swapped = false; //this is created for the optimisation of our code.
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false){ //this means that the array is already sorted till this iteration, so even if we are left with some iterations,
            break;            //then there is no need to go for them.
        }
    }

    cout << "Sorted array is : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}