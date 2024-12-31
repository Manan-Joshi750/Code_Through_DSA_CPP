#include <iostream>
#include <vector>
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

    for (int i = 1; i < size; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    cout << "Updated Array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}