class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int start = points[0][0], end = points[0][1], arrows = 1;
        for(auto it : points){
            if(it[0] > end){
                arrows++, start = it[0], end = it[1];
            }
            else{
                end = min(end, it[1]);
            }
        }
        return arrows;
    }
};