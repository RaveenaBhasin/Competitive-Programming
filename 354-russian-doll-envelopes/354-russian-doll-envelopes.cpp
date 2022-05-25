class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>res;
        for(auto it : envelopes){
            auto x = lower_bound(res.begin(), res.end(), it[1]);
            if(x == res.end()){
                res.push_back(it[1]);
            }
            else{
                *x = it[1];
            }
        }
        return res.size();
    }
};


