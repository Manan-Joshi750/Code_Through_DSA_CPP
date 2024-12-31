/*Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents
the length of each board. Some ‘k’ numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time
to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards. */
#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid){
    int painterCount = 1;
    int boardLength = 0;

    for(int i=0; i<n; i++){
        if(boardLength + arr[i] <=mid){
            boardLength += arr[i];
        } else {
            painterCount++;
            if(painterCount > k || arr[i] > mid){
                return false;
            }
            boardLength = arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int n, int k){
    int start = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start)/2;
    int ans =-1;

    while(start <= end){
        if(isPossible(arr,n,k,mid)){
            ans = mid;
            end = mid -1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cout << "Enter the length of the board which is present at index " << i << " : ";
        cin>> arr[i];
    }

    int k;
    cout << "Enter the number of painters which you will be having to paint your all boards : ";
    cin >> k;

    cout << "Area of the minimum time to get this job done is : " << painterPartition(arr,n,k);
    return 0;
}