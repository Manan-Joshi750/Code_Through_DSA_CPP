/*
Given two arrays, val[] and wt[], representing the values and weights of items, 
and an integer capacity representing the maximum weight a knapsack can hold, 
determine the maximum total value that can be achieved by putting items in the knapsack. 
You are allowed to break items into fractions if necessary.
The task is to return the maximum value as a double, rounded to 6 decimal places.
*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items based on value-to-weight ratio
bool comparator(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value of items that can be put in a knapsack
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), comparator);

    double maxValue = 0.0;

    for (auto& item : items) {
        if (capacity >= item.weight) {
            // Take the full item
            maxValue += item.value;
            capacity -= item.weight;
        } else {
            // Take the fraction of the item
            maxValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(capacity, items);
    cout << fixed << setprecision(6) << "Maximum value in Knapsack = " << result << endl;

    return 0;
}