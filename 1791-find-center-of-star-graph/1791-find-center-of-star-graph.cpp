class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int>mp;
        int n = edges.size();
        for(auto& it : edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int centre;
        for(auto& it : mp){
            if(it.second == n){
                centre = it.first;
                break;
            }
        }
        return centre;
    }
};
