#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number upto which you want to find the sum : ";
    cin >> n;

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }

    cout << "Sum of first " << n << " Natural Numbers is : " << sum;
    return 0;
}