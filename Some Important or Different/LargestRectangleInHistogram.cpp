#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//LARGEST RECTANGLE IN A HISTOGRAM.
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int tp, areaWithTop, i = 0, n = heights.size();
    
    while (i < n) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            tp = s.top();
            s.pop();
            areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
    }
    
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, areaWithTop);
    }
    return maxArea;
}

int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(histogram);
    
    cout << "The largest rectangle area in the histogram is: " << result << endl;  
    return 0;
}
