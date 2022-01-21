class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<bool>&vis, int i) {
        vis[i] = true;
        for(auto it : rooms[i]) {
            if(!vis[it]) {
                dfs(rooms, vis, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        dfs(rooms, visited, 0);
        for(auto it : visited) {
            if(!it) {
                return false;
            }
        }
        return true;
    }
};