class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; 
        vector<bool> arr(n);
        heap.push({ 0, 0 });
        int mincost = 0;
        int remaning = 0;
        while (remaning < n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            if (arr[currNode]) {
                continue;
            }
            
            arr[currNode] = true;
            mincost += weight;
            remaning++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!arr[nextNode]) {
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + 
                                     abs(points[currNode][1] - points[nextNode][1]);
                    
                    heap.push({ nextWeight, nextNode });
                }
            }
        }
        
        return mincost;
    }
};