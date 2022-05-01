class Solution {
public:
    void countIslands(vector<vector<char>>&grid, int currRow, int currCol, int m, int n){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid[currRow][currCol] == '0'){
            return;
        }
        grid[currRow][currCol] = '0';
        countIslands(grid, currRow-1, currCol, m, n);
        countIslands(grid, currRow+1, currCol, m, n);
        countIslands(grid, currRow, currCol+1, m, n);
        countIslands(grid, currRow, currCol-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    countIslands(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};