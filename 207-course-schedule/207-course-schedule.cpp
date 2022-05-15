class Solution {
    vector<vector<int>>formGraph(int n, vector<vector<int>>&pre){
        vector<vector<int>>graph(n);
        for(auto it : pre){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
        }
        return graph;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph = formGraph(numCourses, prerequisites);
        vector<int>inDegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(int it : graph[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        unordered_set<int>st;
        int res = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
                res++;
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(st.find(curr) != st.end()){
                continue;
            }
            st.insert(curr);
            for(int neighbour : graph[curr]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0){
                    q.push(neighbour);
                    res++;
                }
           }
        }
        if(res == numCourses){
            return true;
        }
        return false;
    }
};