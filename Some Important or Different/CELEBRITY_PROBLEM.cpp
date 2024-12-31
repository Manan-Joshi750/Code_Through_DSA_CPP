#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        for(int i = 0; i < n; i++) {
            s.push(i);
        }   
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M, a, b)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int ans = s.top();

        int zeroCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }

        if(zeroCount != n)
            return -1;
        
        int oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }

        if(oneCount != n - 1)
            return -1;
        
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of people at the party : ";
    cin >> n;
    
    vector<vector<int>> M(n, vector<int>(n, 0));
    cout << ".....Enter the matrix (each row in a new line)....." << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    Solution ob;
    int result = ob.celebrity(M, n);
    if(result == -1)
        cout << "There is no celebrity in the party.\n";
    else
        cout << "The celebrity is at index " << result << ".\n";

    return 0;
}