#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i >= str.length()) {
        if(output.length() > 0){ // apply this condition only when we don't want empty string as an subsequence, otherwise don't apply it. 
            ans.push_back(output);
        } 
        return ;
    }
    
    //Exclusion case
    solve(ans, str, output, i+1);

    //Inclusion case
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
	
}

int main(){
    string str;
    cout << "Enter any string : ";
    cin >> str;

    vector<string> result = subsequences(str);

    cout << "All possible subsequences are : ";
    for(size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}