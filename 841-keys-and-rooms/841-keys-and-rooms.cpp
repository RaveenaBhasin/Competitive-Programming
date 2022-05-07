class Solution {
public:
    void dfs(vector<vector<int>>&rooms, int currIndex, vector<bool>&vis){
        vis[currIndex] = true;
        for(auto it : rooms[currIndex]){
            if(!vis[it]){
                dfs(rooms, it, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, 0, vis);
        for(auto it : vis){
            if(!it){
                return false;
            }
        }
        return true;
    }
};