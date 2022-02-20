class Solution {
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        else{
            return a[0] < b[0];
        }
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size(), temp = intervals[0][1];
        int res = n;
        for(int i = 1; i < n; i++){
            if(intervals[i][1] <= temp){
                res--;
            }
            else{
                temp = intervals[i][1];
            }
        }
        return res;
    }
};