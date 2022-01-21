class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(vector<vector<int>>&graph, int currIndex, vector<int>&path){
        path.push_back(currIndex);
        if(currIndex == graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto it: graph[currIndex]){
                dfs(graph, it, path);
            }
        }
        //Backtrack
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<int>path;
        dfs(graph, 0, path);
        return ans;
    }
};