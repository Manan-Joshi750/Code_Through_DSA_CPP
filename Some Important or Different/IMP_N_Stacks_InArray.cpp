/*Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :
Type 1: for push(X, M) operation.
Type 2: for pop(M) operation. */
#include <iostream>
using namespace std;

class NStack {
    int* arr;
    int* top;
    int* next;
    
    int n, s;
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S) {
        n = N; // Number of stacks
        s = S; // Size of the array

        arr = new int[s]; // Array to store elements
        top = new int[n]; // Array to store indexes of top elements of each stack
        next = new int[s]; // Array to store next available index or next element in a stack
        
        // Initialize top array
        for (int i = 0; i < n; i++) {
            top[i] = -1; // -1 indicates that the stack is empty
        }
        
        // Initialize next array
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1; // Each index points to the next index
        }
        next[s - 1] = -1; // Last index of the array points to -1
        
        // Initialize freespot
        freespot = 0; // First index of the array is the initial free spot
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // Check for overflow
        if (freespot == -1) {
            return false; // No space left to push new element
        }
        
        // Find index to push the element
        int index = freespot;
        
        // Insert the element into the array
        arr[index] = x;
        
        // Update freespot to the next available index
        freespot = next[index];
        
        // Link the new element to the previous top element of stack `m`
        next[index] = top[m - 1];
        
        // Update the top to the new index
        top[m - 1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // Check for underflow
        if (top[m - 1] == -1) {
            return -1; // Stack `m` is empty
        }
        
        // Get the index of the top element of stack `m`
        int index = top[m - 1];
        
        // Update the top to the next element in the stack
        top[m - 1] = next[index];
        
        // Link the current index back to the free spot list
        next[index] = freespot;
        
        // Update the freespot to the current index
        freespot = index;
        
        return arr[index]; // Return the popped element
    }

    // Destructor to clean up dynamically allocated memory
    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    // Create 3 stacks in an array of size 10
    NStack st(3, 10);

    // Push elements into different stacks
    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);
    st.push(50, 3);

    // Pop elements from the stacks
    cout << "Popped from stack 1: " << st.pop(1) << endl; // Should return 20
    cout << "Popped from stack 2: " << st.pop(2) << endl; // Should return 30
    cout << "Popped from stack 3: " << st.pop(3) << endl; // Should return 50

    return 0;
}