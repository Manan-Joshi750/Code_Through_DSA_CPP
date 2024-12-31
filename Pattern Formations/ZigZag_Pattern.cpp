#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the height of the pattern : ";
    cin >> n;
//In this code, the number of rows are fixed as for a zig-zag patterm, we need to think of a particular condition.
//Like here the conditions were related to 2 and 4 when the number of rows were 3.
    for(int i=1; i<=3; i++){
        for(int j=1; j<=n; j++){
            if((i+j) % 4 == 0 || (i==2 && j%4 == 0)){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}