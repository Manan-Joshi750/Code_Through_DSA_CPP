/*We will be given an array arr of integer numbers where arr[i] represents the number of pages in ith book. 
There are m number of students and the task is to allocate all the books to their students. Allocate books in such a way that : 
1. Each student gets atleast one book
2. Each book should be allocated to a student
3. Book allocation should be in contigous manner.
You have to allocate books to m students such that maximum number of pages assigned to a student is minimum. */
#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <=mid){
            pageSum += arr[i];
        } else {
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[], int n, int m){
    int start = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start)/2;
    int ans =-1;

    while(start <= end){
        if(isPossible(arr,n,m,mid)){
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
        cout << "Enter the number of pages, the book is having at index " << i << " : ";
        cin>> arr[i];
    }

    int m;
    cout << "Enter the number of students among which you have to allocate the books : ";
    cin >> m;

    cout << "Minimum number of pages are : " << bookAllocation(arr,n,m);
    return 0;
}