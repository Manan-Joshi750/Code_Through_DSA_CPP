#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        map<char, int> m;
        string ans = "";
        queue<char> q;
        
        for(int i = 0; i < A.length(); i++) {
            char ch = A[i];
            
            // Push current character to the queue
            q.push(ch);
            // Increment frequency count in the map
            m[ch]++;
            
            // Process the queue to find the first non-repeating character
            while(!q.empty()) {
                // If the front character has a frequency greater than 1, remove it
                if(m[q.front()] > 1){
                    q.pop();
                }
                else {
                    // If the front character is non-repeating, add it to the answer
                    ans.push_back(q.front());
                    break;
                }
            }
            // If the queue is empty, append '#' indicating no non-repeating character (this was given in the question)
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};

int main(){
    int tc;
    cin >> tc;  // Number of test cases
    while(tc--){
        string A;
        cin >> A;  // Input string
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";  // Output the result
    }
    return 0;
}