// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void GenerateAllPaths(vector<vector<int>> &grid, int &n, int currentRow, int currentCol, string &currentPath, vector<string> &paths) {
        if(currentRow < 0 || currentRow >=n || currentCol < 0 || currentCol >=n) {
            return;
        }
        
        if(grid[currentRow][currentCol] == 0) {
            return;
        }
        
        if(currentRow == n-1 && currentCol == n-1) {
            paths.push_back(currentPath);
            return;
        }
        
        grid[currentRow][currentCol] = 0;
        
        // Down Movement
        currentPath += "D";
        GenerateAllPaths(grid, n, currentRow+1, currentCol, currentPath, paths);
        currentPath.pop_back();
        
        // Left Movement
        currentPath += "L";
        GenerateAllPaths(grid, n, currentRow, currentCol-1, currentPath, paths);
        currentPath.pop_back();
        
        // Right Movement
        currentPath += "R";
        GenerateAllPaths(grid, n, currentRow, currentCol+1, currentPath, paths);
        currentPath.pop_back();
        
        // Up Movement
        currentPath += "U";
        GenerateAllPaths(grid, n, currentRow-1, currentCol, currentPath, paths);
        currentPath.pop_back();
        
        grid[currentRow][currentCol] = 1;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string res = "";
        vector<string>ans;
        GenerateAllPaths(m, n, 0, 0, res, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends