#include<iostream>
using namespace std;

int main(){
    int n1, n2, n3;
    cout << "Enter the values of n1, n2 and n3 respectively : ";
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2], m2[n2][n3], ans[n1][n3];

    cout << "For Matrix 1 --> " << endl;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            cout << "Enter the value at index " << i << j << " : ";
            cin >> m1[i][j];
        }
    }

    cout << "For Matrix 2 --> " << endl;
    for(int i=0; i<n2; i++){
        for(int j=0; j<n3; j++){
            cout << "Enter the value at index " << i << j << " : ";
            cin >> m2[i][j];
        }
    }

    for(int i=0; i<n1; i++){
        for(int j=0; j<n3; j++){
            ans[i][j] = 0;
        }
    }

    for(int i=0; i<n1; i++){
        for(int j=0; j<n3; j++){
            for(int k=0; k<n2; k++){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    cout << "Resultant Matrix is --> " << endl;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n3; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}