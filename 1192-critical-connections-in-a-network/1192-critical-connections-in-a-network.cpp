class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& it : connections) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>> bridges;
        vector<int> disc(n, -1), low(n, -1);
        
        std::function<void (int, int, int)> dfs = [&](int node, int parent, int level) {
            if (disc[node] >= 0) return;  

            disc[node] = low[node] = level;
            for (auto& nei : graph[node]) {
                if (nei == parent) continue;
                if (disc[nei] < 0) {
                    dfs(nei, node, level + 1);
                    low[node] = min(low[node], low[nei]);
                    if (disc[node] < low[nei]){
                        bridges.push_back({node, nei});
                    }
                } else {
                    low[node] = min(low[node], disc[nei]);
                }
            }
        };
        
        dfs(0, -1, 0);
        return bridges;
    }
};