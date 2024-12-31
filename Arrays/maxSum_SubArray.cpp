#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    //Brute Force Approach.
    int maxSum1 = INT_MIN;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            maxSum1 = max(maxSum1, sum);
        }
    }
    cout << "Maximum sum obtained : " << maxSum1 << endl;

    //Prefix Sum Technique.
    int cumsum[size+1];
    cumsum[0] = 0;
    for(int i=1; i<=size; i++){
        cumsum[i] = cumsum[i-1] + arr[i-1];
    }

    int maxSum2 = INT_MIN;
    for(int i=1; i<=size; i++){
        int sum = 0;
        maxSum2 = max(maxSum2, cumsum[i]);
        for(int j=1; j<=i; j++){
            sum = cumsum[i] - cumsum[j-1];
            maxSum2 = max(maxSum2, sum);
        }
    }
    cout << "Maximum sum obtained : " << maxSum2 << endl;

    //Kadane's Algorithm.
    int currentSum = 0;
    int maxSum3 = INT_MIN;
    for(int i=0; i<size; i++){
        currentSum += arr[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        maxSum3 = max(maxSum3, currentSum);
    }
    cout << "Maximum sum obtained : " << maxSum3;
   return 0; 
}