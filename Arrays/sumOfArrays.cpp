#include<iostream>
#include<vector>
using namespace std;

void arraySum(int arr1[], int arr2[], int n1, int n2) {
    int array1num = 0;
    int array2num = 0;
    for (int i = 0; i < n1; i++) {
        array1num = array1num * 10 + arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        array2num = array2num * 10 + arr2[i];
    }

    int sumOfArrays = array1num + array2num;
    // Determine the number of digits in the result
    int tempSum = sumOfArrays;
    int numDigits = 0;
    do {
        numDigits++;
        tempSum /= 10;
    } while (tempSum > 0);

    int arr3[numDigits];
    for (int i = numDigits - 1; i >= 0; i--) {
        arr3[i] = sumOfArrays % 10;
        sumOfArrays /= 10;
    }

    cout << "Resultant Sum Array is: [ ";
    for (int i = 0; i < numDigits; i++) {
        cout << arr3[i] << " ";
    }
    cout << "]";
}

int main(){
    int n1;
    cout << "Enter the size of first array : ";
    cin >> n1;

    int arr1[n1];
    for(int i=0; i<n1; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr1[i];
    }

    int n2;
    cout << "Enter the size of second array : ";
    cin >> n2;

    int arr2[n2];
    for(int i=0; i<n2; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr2[i];
    }

    arraySum(arr1, arr2, n1, n2);
    return 0;
}