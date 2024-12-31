/* Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it 
while value 1 at a cell in the matrix represents that rat can be travel through it.
Note : In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. 
In case of no path, return an empty list. The driver will output "-1" automatically. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int m, vector<vector<int>> visited, vector<vector<int>> &maze){
    if((x >= 0 && x < m) && (y >= 0 && y < m) && visited[x][y] == 0 && maze[x][y] == 1){
        return true;
    } else {
        return false;
    }
}

void solve(vector<vector<int>> &maze, int m, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
    if(x == m-1 && y == m-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    //If we are going down
    int newx = x + 1;
    int newy = y;
    if(isSafe(newx, newy, m, visited, maze)){
        path.push_back('D');
        solve(maze, m, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //If we are going towards left
    newx = x;
    newy = y - 1;
    if(isSafe(newx, newy, m, visited, maze)){
        path.push_back('L');
        solve(maze, m, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //If we are going towards right
    newx = x;
    newy = y + 1;
    if(isSafe(newx, newy, m, visited, maze)){
        path.push_back('R');
        solve(maze, m, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //If we are going up
    newx = x - 1;
    newy = y;
    if(isSafe(newx, newy, m, visited, maze)){
        path.push_back('U');
        solve(maze, m, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &maze, int m){
    vector<string> ans;
    if(maze[0][0] == 0){
        return ans;
    }
    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = maze;
    //Initialise it with 0
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(maze, m, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int m;
    cout << "Enter the size of the maze : ";
    cin >> m;

    vector<vector<int>> maze(m, vector<int>(m));
    cout << "Enter the elements of the maze (0 or 1) -->" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter the element at index " << i << j << " : ";
            cin >> maze[i][j];
        }
    }

    vector<string> result = findPath(maze, m);
    if(result.empty()){
        cout << "There is NO POSSIBLE path for the rat to come out of the maze....." << endl;
    } else {
        cout << "All possible paths are : ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}