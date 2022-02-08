class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        if(grid[sr][sc] == newColor){
            return grid;
        }
        sinkGraph(grid, sr, sc, grid[sr][sc], grid.size(), grid[0].size(), newColor);
        return grid;
    }
    
    void sinkGraph(vector<vector<int>>&graph, int currRow, int currCol, int startColor, int m, int n, int newColor){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || graph[currRow][currCol] != startColor){
            return;
        }
        graph[currRow][currCol] = newColor;
        //up direction
        sinkGraph(graph, currRow - 1, currCol, startColor, m, n, newColor);
        //right direction
        sinkGraph(graph, currRow, currCol + 1, startColor, m, n, newColor);
        //left direction
        sinkGraph(graph, currRow, currCol - 1, startColor, m, n, newColor);
        //down direction
        sinkGraph(graph, currRow + 1, currCol, startColor, m, n, newColor);
        return;
    }
};