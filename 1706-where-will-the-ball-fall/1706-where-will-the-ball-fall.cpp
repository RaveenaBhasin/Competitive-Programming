class Solution {
public:
    int helper(vector<vector<int>>&grid, int i, int j) {
        if(i >= grid.size()) {
            return j;
        }
        if(grid[i][j] == 1 && j+1 < grid[0].size() && grid[i][j+1] == 1) {
            return helper(grid, i+1, j+1);
        }
        else if(grid[i][j] == -1 && j-1 >= 0 && grid[i][j-1] == -1) {
            return helper(grid, i+1, j-1);
        }
        else {
            return -1;
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>res(m);
        for(int i = 0; i < m; i++) {
            res[i] = helper(grid, 0, i);
        }
        return res;
    }
};



