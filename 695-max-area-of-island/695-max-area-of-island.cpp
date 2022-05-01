class Solution {
public:
    int findArea(vector<vector<int>>&grid, int currRow, int currCol, int m ,int n){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid[currRow][currCol] == 0){
            return 0;
        }
        grid[currRow][currCol] = 0;
        int area = 1;
        area += findArea(grid, currRow-1, currCol, m, n);
        area += findArea(grid, currRow+1, currCol, m, n);
        area += findArea(grid, currRow, currCol-1, m, n);
        area += findArea(grid, currRow, currCol+1, m, n);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, findArea(grid, i, j, m, n));
                }
            }
        }
        return maxArea;
        
    }
};