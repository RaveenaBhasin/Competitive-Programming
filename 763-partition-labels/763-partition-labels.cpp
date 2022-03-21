class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        vector<int>res;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]] = i;
        }
        int cnt1 = -1, cnt2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] > cnt2){
                cnt2 = mp[s[i]];
            }
            if(cnt2 == i){
                res.push_back(cnt2 - cnt1); 
                cnt1 = cnt2;
            }
        }
        return res;
    }
};
