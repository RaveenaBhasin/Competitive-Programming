class Solution {
public:
    vector<vector<int>>allPaths;
    void dfs(vector<vector<int>>&graph, int currIndex, vector<int>&path){
        path.push_back(currIndex);
        if(currIndex == graph.size()-1){
            allPaths.push_back(path);
        }
        else{
            for(auto it : graph[currIndex]){
                dfs(graph, it, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>currPath;
        dfs(graph, 0, currPath);
        return allPaths;
    }
};