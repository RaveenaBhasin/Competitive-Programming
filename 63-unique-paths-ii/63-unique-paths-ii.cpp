class Solution {
public:
    int totalWays(int currRow, int currCol, int m, int n, vector<vector<int>>& obstacleGrid, unordered_map<string, int>&mp){
        if(currRow >= m || currCol >=n || obstacleGrid[currRow][currCol]){
            return 0;
        }
        if(m-1 == currRow && n-1 == currCol){
            return 1;
        }
        string currKey = to_string(currRow) + "_" + to_string(currCol);
        if(mp.find(currKey) != mp.end()){
            return mp[currKey];
        }
        int right = totalWays(currRow + 1, currCol, m, n, obstacleGrid, mp);
        int down = totalWays(currRow, currCol + 1, m, n, obstacleGrid, mp);
        mp[currKey] = right + down;
        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string, int>mp;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return totalWays(0, 0, m, n, obstacleGrid, mp);
    }
};