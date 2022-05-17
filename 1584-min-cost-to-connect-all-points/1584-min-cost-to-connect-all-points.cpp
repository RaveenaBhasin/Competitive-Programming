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
        else if(rank[x] > rank[y]){
            parent[x] = y;
        }
        else if(rank[x] < rank[y]){
            parent[y] = x;
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
        int src, dest, weight;
        Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight){}
        static bool cmp(Edge &e1, Edge &e2){
            return e1.weight < e2.weight;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge>graph;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.push_back(Edge(i, j, weight));
            }
        }
        sort(graph.begin(), graph.end(), Edge::cmp);
        DisjointSet ds(n);
        int minCost = 0;
        for(int i = 0, size = 0; i < graph.size(), size < n-1; i++){
            Edge e = graph[i];
            int u = e.src, v = e.dest;
            if(ds.Union(u, v)){
                minCost += e.weight;
                size++;
            }
        }
        return minCost;
    }
};