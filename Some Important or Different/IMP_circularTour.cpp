#include<bits/stdc++.h>
using namespace std;

// Structure to represent a petrol pump
struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    // Function to find the starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        int deficit = 0;   // Deficit to track the shortage of petrol
        int balance = 0;   // Current balance of petrol
        int start = 0;     // Starting point of the tour
        
        for(int i = 0; i < n; i++) {
            // Update the balance petrol after covering the distance from the current pump
            balance += p[i].petrol - p[i].distance;
            
            // If balance is negative, update the starting point and add the deficit
            if(balance < 0) {
                start = i + 1; //basically every previous block is giving some positive contribution to the next block. So is we are having blocks
                //A,B,C and D, then if we aren't able to reach to D from A, then it will also not be possible to reach D from either B or C. 
                deficit += balance;
                balance = 0;
            }
        }
        
        // If the total petrol (balance + deficit) is non-negative, return the starting point
        if(balance + deficit >= 0) 
            return start;
        
        // If not, return -1 indicating that the tour is not possible
        return -1;
    }
};

// Driver code to test the function
int main() {
    int t;
    cin >> t;  // Number of test cases
    while(t--) {
        int n;
        cin >> n;  // Number of petrol pumps
        petrolPump p[n];
        
        // Input petrol and distance for each petrol pump
        for(int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        
        Solution obj;
        cout << obj.tour(p, n) << endl;  // Output the starting point for the tour
    }
    return 0;
}