class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeIntervals;
        if(intervals.size() == 0){
            return mergeIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= temp[1]){  //overlapping
                temp[1] = max(temp[1], it[1]);
            }
            else{
                mergeIntervals.push_back(temp);   //not overlapping
                temp = it;
            }
        }
        mergeIntervals.push_back(temp);
        return mergeIntervals;
    
    }
};
// T.C : O(nlogn)  S.C : O(n)