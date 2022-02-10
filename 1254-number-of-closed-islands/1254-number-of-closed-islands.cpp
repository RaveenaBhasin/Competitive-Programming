class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((grid[i][j]==0 && sinkIsland(grid, i, j, m, n)) == true){
                    count++;
                }
            }
        }
        return count;
    }
    
    bool sinkIsland(vector<vector<int>>&grid, int currRow, int currCol, int m, int n){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n){
            return false;
        }
        if(grid[currRow][currCol] == 1){
            return true;
        }
        grid[currRow][currCol] = 1;
        bool a = sinkIsland(grid, currRow - 1, currCol, m, n);
        bool b = sinkIsland(grid, currRow, currCol - 1, m ,n);
        bool c = sinkIsland(grid, currRow, currCol + 1, m, n);
        bool d = sinkIsland(grid, currRow + 1, currCol, m, n);
        return a&b&c&d;
    }
    

};