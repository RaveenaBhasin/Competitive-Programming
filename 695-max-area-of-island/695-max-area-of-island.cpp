class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mx = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    mx = max(mx, area(grid, r, c, m, n));
                }
            }
        }
        return mx;
    }
    
    int area(vector<vector<int>>& grid, int r, int c, int m, int n) {
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        int a = 0;
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            if (r + x[i] >=0 && r + x[i] < m && c + y[i] >=0 && c + y[i] < n && grid[r + x[i]][c + y[i]] == 1) {
                a += area(grid, r + x[i], c + y[i], m, n); 
            }
        }
        return a + 1;
    }

};