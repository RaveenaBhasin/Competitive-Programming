class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int node1 = edges[0][0];
        int node2 = edges[0][1];
        if(edges[1][0] == node1 || edges[1][1] == node1){
            return node1;
        }
        return node2;
    }
};
