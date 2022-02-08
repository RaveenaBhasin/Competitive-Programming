class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        for(int currentRow = 0; currentRow < m; currentRow++){
            for(int currentCol = 0; currentCol < n; currentCol++){
                if(grid[currentRow][currentCol] == '1'){
                    answer += 1;
                    sinkIsland(grid, currentRow, currentCol, m, n);
                }
            }
        }
        return answer;
    }
    
    void sinkIsland(vector<vector<char>>&grid, int currentRow, int currentCol, int m, int n){
        if(currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n || grid[currentRow][currentCol] == '0'){
            return;
        }
        //Marking this as visited
        grid[currentRow][currentCol] = '0';
        //up 
        sinkIsland(grid, currentRow - 1, currentCol, m, n);
        //down
        sinkIsland(grid, currentRow + 1, currentCol, m, n);
        //left
        sinkIsland(grid, currentRow, currentCol - 1, m, n);
        //right
        sinkIsland(grid, currentRow, currentCol + 1, m, n);
        return;
        
    }
};