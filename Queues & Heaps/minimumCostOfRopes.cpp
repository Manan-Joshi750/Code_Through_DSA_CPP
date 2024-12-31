#include <iostream>
#include <vector>
#include <queue>  
using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int rope : ropes) {
        minHeap.push(rope);
    }

    int totalCost = 0;

    // While there is more than one rope in the heap
    while (minHeap.size() > 1) {
        // Extract the two smallest ropes
        int firstRope = minHeap.top();
        minHeap.pop();
        int secondRope = minHeap.top();
        minHeap.pop();

        // The cost of connecting the two ropes
        int cost = firstRope + secondRope;
        totalCost += cost;

        // Insert the resulting rope back into the heap
        minHeap.push(cost);
    }

    // Return the total cost of connecting all ropes
    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    int result = minCostToConnectRopes(ropes);
    cout << "Minimum cost to connect all ropes: " << result << endl;
    return 0;
}