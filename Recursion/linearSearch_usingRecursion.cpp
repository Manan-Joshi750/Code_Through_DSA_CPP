#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key){
    if(n == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    } else {
        bool remainingPart = linearSearch(arr + 1, n - 1, key);
        return remainingPart + 1;
    }
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    int key;
    cout << "Enter the value of key to search : ";
    cin >> key;

    bool ans = linearSearch(arr,n,key);
    if(ans){
        cout << "key found at position " << ans;
    } else {
        cout << " key not found";
    }

    delete []arr;
    return 0;
}