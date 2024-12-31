#include <iostream> 
using namespace std; 
//Function to print crown pattern.
void crown(int length, int height){ 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < length; j++) {  
            // for first row, print '*' i.e, for top part of crown
            if (i == 0) { 
                // print '*' at first, middle and last column 
                if (j == 0 || j == height || j == length - 1) { 
                    cout << "*"; 
                } 
                else { 
                    cout << " "; 
                } 
            }
            // print '*' at base of crown i.e, for last row
            else if (i == height - 1) { 
                cout << "*"; 
            } 
            // fill '*' to make a perfect crown 
            else if ((j < i || j > height - i) && 
                     (j < height + i || j >= length - i)) 
                cout << "*"; 
            else
                cout << " "; 
        } 
        cout<<endl; 
    } 
} 

int main(){ 
    int length = 25; 
    int height = (length - 1) / 2; 
    crown(length, height); 
    return 0; 
} 