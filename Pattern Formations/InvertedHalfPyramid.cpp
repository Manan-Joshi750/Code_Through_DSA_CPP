#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the height of the pyramid : ";
    cin >> n;

    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
//How it looks like after 180 degree rotation.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j<= n-i){
                cout << "  ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}