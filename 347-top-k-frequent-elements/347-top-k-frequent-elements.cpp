class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto &it : nums){
            mp[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto &it : mp){
            cout<<it.first<<" "<<it.second<<endl;
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;
        while(pq.size() > 0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};