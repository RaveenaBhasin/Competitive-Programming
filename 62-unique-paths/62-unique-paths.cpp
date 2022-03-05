class Solution {
public:
    int totalPaths(int currRow, int currCol, int m, int n, unordered_map<string,int>&mp){
        if(m == currRow && n == currCol){
            return 1;
        }
        if(currRow > m || currCol > n){
            return 0;
        }
        string currKey = to_string(currRow) + "_" + to_string(currCol);
        if(mp.find(currKey) != mp.end()){
            return mp[currKey];
        }
        int right = totalPaths(currRow + 1, currCol, m, n, mp);
        int down = totalPaths(currRow, currCol + 1, m, n, mp);
        mp[currKey] = right + down;
        return right + down;
    }
    int uniquePaths(int m, int n) {
        unordered_map<string, int>mp;
        return totalPaths(0, 0, m-1, n-1, mp);
    }
};