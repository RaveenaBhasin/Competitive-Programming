class DisjointSet{
public:
    vector<int>rank;
    vector<int>parent;
    
    DisjointSet(int n){
        rank = vector<int>(n);
        parent = vector<int>(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(parent[node] != node){
            return findParent(parent[node]);
        }
        return node;
    }
    
    bool Union(int node1, int node2){
        int x = findParent(node1);
        int y = findParent(node2);
        if(x == y){
            return false;
        }
        else if(rank[x] < rank[y]){
            parent[y] = x;
        }
        else if(rank[x] > rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x] = rank[x] + 1;
        }
        return true;
    }
};
class Solution {
    struct Edge{
        int src, dest, wt;
        Edge(int src, int dest, int wt) : 
            src(src), dest(dest), wt(wt){}
        static bool cmp(Edge &n1, Edge& n2){
            return n1.wt < n2.wt;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge>graph;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.push_back(Edge(i, j, weight));
            }
        }
        sort(graph.begin(), graph.end(), Edge::cmp);
        DisjointSet ds(n);
        int minCost = 0;
        for(int i = 0, size = 0; size < n-1, i < graph.size(); i++){
            Edge e = graph[i];
            int u = e.src, v = e.dest;
            if(ds.Union(u, v)){
                minCost += e.wt;
                size++;
            }
        }
        return minCost;
    }
};