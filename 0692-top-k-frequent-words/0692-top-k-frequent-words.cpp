class Solution {
public:
    struct Comparator {
        bool operator()(pair<int, string>&p1, pair<int, string>&p2){
            return p2.first > p1.first or (p1.first == p2.first and p1.second > p2.second);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>res;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator>pq;
        unordered_map<string, int>mp;
        for(auto it : words){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        while(k != 0){
            auto u = pq.top();
            pq.pop();
            res.push_back(u.second);
            k--;
        }
        return res;
    }
};
