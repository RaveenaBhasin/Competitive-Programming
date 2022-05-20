class Solution {
    bool isValid(vector<vector<int>>&grid, vector<vector<bool>>&vis, int row, int col, int n){
        if(row < 0 || row >= n || col < 0 || col >= n || vis[row][col] == 1 || grid[row][col] != 0){
            return false;
        }
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        queue<pair<int, int>>q;
        if(!grid[0][0]){
            q.push({0,0});
            vis[0][0] = 1;
        }
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++){
                int u = q.front().first;
                int v = q.front().second;
                q.pop();
                if(u == n-1 && v == n-1){
                    return res;
                }
                for(int row = u-1; row <= u+1; row++){
                    for(int col = v-1; col <= v+1; col++){
                        if(isValid(grid, vis, row, col, n)){
                            q.push({row, col});
                            vis[row][col] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};