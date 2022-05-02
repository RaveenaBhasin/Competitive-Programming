class Solution {
public:
    void enclaveFound(vector<vector<int>>&grid, int currRow, int currCol, int m, int n){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid[currRow][currCol] == 0){
            return;
        }
        grid[currRow][currCol] = 0;
        enclaveFound(grid, currRow+1, currCol, m, n);
        enclaveFound(grid, currRow-1, currCol, m, n);
        enclaveFound(grid, currRow, currCol+1, m, n);
        enclaveFound(grid, currRow, currCol-1, m, n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        //Boundary 1's
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && grid[i][j] == 1){
                    enclaveFound(grid, i, j, m, n);            
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};