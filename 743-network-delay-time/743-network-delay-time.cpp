class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>graph[n+1];
        for(int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto x : graph[u]){
                int v = x.first;
                int wt = x.second;
                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < dist.size(); i++){
            ans = max(ans, dist[i]);
        }
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};