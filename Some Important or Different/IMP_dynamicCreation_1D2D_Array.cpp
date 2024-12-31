#include<iostream>
using namespace std;
//So this is basically DMA where we are creating 1D/2D array dynamically using heap memory as there are 2 parts of memory : stack and heap. 
//int i = 5, int arr[5], and like these are example of static creation of variables/arrays and all. 
/*While int *i = new int i, int *arr = new int[n] and like these are example of dynamic creation of variables/arrays and all.
Now you might be wondering why we have stored the dynamically created array using a pointer because a pointer is only used to store the address of a variable.
Yessss... You are correct. In case of DMA, either we write new int[n] or new int i or anything, this syntax of creation returns a address 
and we need to store it somewhere, so there is none better than the pointer to do that.... */
//If we are writing int i = 5, then this in total occupies a memory of 4 bytes as it is of integer data type. 
/*However in case of something like int *arr = new int[n], the pointer occupies 4 bytes(in 32 bit system)/ 8 bytes(in 64 bit system)
and n*4 by the integer array, so in total (n*4 + 4 or n*4 + 8). 
Now when we use these things inside some particular block of code like inside a function using {}, then in case of static memory allocation, the memory gets
freed when we come out of that block of code but in case of dynamic memory allocation, the memory occupied by the pointer gets freed but not the one which 
is given by the heap, so as we keep on entering and leaving that block of code in which we are dynamically allocating memory, the heap created memory keeps
on accumulating and then results in the system crashing when storage gets full. So in order to free the memory, we can use the "delete" keyword. 
SO WHENEVER WE ARE ALLOCATING MEMORY USING HEAP, IT IS ALSO OUR RESPONSIBILITY TO FREE THAT MEMORY AS WELL (reason is explained above). */

int main(){
    //Dynamic Creation and taking the elements as input from the user for 1D Array
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    cout << "THANK YOU FOR GIVING THE INFORMATION.....";
    cout << "NOW HEADING TOWARDS FREEING THIS ALLOCATED MEMORY.....";
    delete []arr;

    //Dynamic Creation and taking the elements as input from the user for 2D Array with SAME NUMBER OF ROWS AND COLUMNS
    int m;
    cout << "Enter the size of the 2D array : ";
    cin >> m;

    int **twoD_arr1 = new int*[m];
    for(int i=0; i<m; i++){
        twoD_arr1[i] = new int[m];
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout << "Enter the element at index " << i << j << " : ";
            cin >> twoD_arr1[i][j];
        }
    }

    cout << "THANK YOU FOR GIVING THE INFORMATION.....";
    cout << "NOW HEADING TOWARDS FREEING THIS ALLOCATED MEMORY.....";

    for(int i=0; i<m; i++){
        delete [] twoD_arr1[i];
    }
    delete []twoD_arr1;

    //Dynamic Creation and taking the elements as input from the user for 2D Array with DIFFERENT NUMBER OF ROWS AND COLUMNS
    int rows;
    cout << "Enter the number of rows of the 2D array : ";
    cin >> rows;

    int columns;
    cout << "Enter the number of rows of the 2D array : ";
    cin >> columns;

    int **twoD_arr2 = new int*[rows];
    for(int i=0; i<rows; i++){
        twoD_arr2[i] = new int[columns];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << "Enter the element at index " << i << j << " : ";
            cin >> twoD_arr2[i][j];
        }
    }

    cout << "THANK YOU FOR GIVING THE INFORMATION.....";
    cout << "NOW HEADING TOWARDS FREEING THIS ALLOCATED MEMORY.....";

    for(int i=0; i<rows; i++){
        delete [] twoD_arr2[i];
    }
    delete []twoD_arr2;
    return 0;
}