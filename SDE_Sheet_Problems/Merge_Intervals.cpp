class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeinterval;
        if(intervals.size() == 0){
            return mergeinterval;
        }
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        for(auto it: intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1], temp[1]);
            }
            else{
                mergeinterval.push_back(temp);
                temp = it;
            }
        }
        mergeinterval.push_back(temp);
        return mergeinterval;
    }
};
//T.C : O(nlogn) + O(n)   S.C : O(N^2)