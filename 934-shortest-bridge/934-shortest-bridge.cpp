class Solution {
public:
    void floodFill(vector<vector<int>>&grid, int i, int j, int m, int n, vector<pair<int, int>>&r){
        if(i<0 || i>=m || j<0 || j>= n || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        r.push_back(make_pair(i, j));
        floodFill(grid, i+1, j, m, n, r);
        floodFill(grid, i-1, j, m, n, r);
        floodFill(grid, i, j+1, m, n, r);
        floodFill(grid, i, j-1, m, n, r);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>>x;
        vector<pair<int, int>>y;
        int m = grid.size(), n = grid[0].size();
        int noOfIslands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    noOfIslands++;
                    if(noOfIslands == 1){
                        floodFill(grid, i, j, m, n, x);
                    }
                    if(noOfIslands == 2){
                        floodFill(grid, i, j, m, n, y);
                    }
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < y.size(); j++){
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second)-1;
                if(dist < mini){
                    mini = dist;
                }
            }
        }
        return mini;
    }
};