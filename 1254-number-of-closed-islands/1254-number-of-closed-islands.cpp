class Solution {
public:
    bool isIsland(vector<vector<int>>&grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }
        grid[i][j] = 1;
        bool d1 = isIsland(grid, i+1, j, m, n);
        bool d2 = isIsland(grid, i-1, j, m, n);
        bool d3 = isIsland(grid, i, j+1, m, n);
        bool d4 = isIsland(grid, i, j-1, m, n);
        return d1&d2&d3&d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 && isIsland(grid, i, j, m, n)){
                    count++;
                }
            }
        }
        return count;
    }
};