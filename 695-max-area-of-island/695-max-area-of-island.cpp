class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int currRow = 0; currRow < m; currRow++){
            for(int currCol = 0; currCol < n; currCol++){
                if(grid[currRow][currCol] == 1){
                    ans = max(ans, sinkIsland(grid, currRow, currCol, m, n));
                }
            }
        }
        return ans;
    }
    
    int sinkIsland(vector<vector<int>>&grid, int currRow, int currCol, int m, int n){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid[currRow][currCol] == 0){
            return 0;
        }
        grid[currRow][currCol] = 0;
        int a = sinkIsland(grid, currRow - 1, currCol, m, n);
        int b = sinkIsland(grid, currRow + 1, currCol, m, n);
        int c = sinkIsland(grid, currRow, currCol - 1, m, n);
        int d = sinkIsland(grid, currRow, currCol + 1, m, n);
        return 1+a+b+c+d;
    }
};