#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int lowerBound, upperBound, flag;
    cout << "Enter the lowerbound of the interval : ";
    cin >> lowerBound;
    cout << "Enter the upperbound of the interval : ";
    cin >> upperBound;

    cout << "Prime numbers between " << lowerBound << " to " << upperBound << " are : ";
    for(int range=lowerBound; range<=upperBound; range++){
        if(range == 1 || range == 0){
            continue;
        }
        flag = 1;
        for(int i=2; i<=sqrt(range); i++){
            if(range % i == 0){
                flag = 0;
				break;
            }
        }

        if(flag == 1){
            cout << range << " ";
        }
    }
    return 0;
}