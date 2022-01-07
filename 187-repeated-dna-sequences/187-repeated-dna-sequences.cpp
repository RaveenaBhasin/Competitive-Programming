class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string, int>mp;
        if(s.size()<10){
            return res;
        }
        for(int i = 0; i < s.size()-9; i++) {
            mp[s.substr(i, 10)]++;
        }
        for(int i = 0; i < s.size()-9; i++) {
            if(mp.find(s.substr(i, 10))->second > 1){
                res.push_back(s.substr(i, 10));
                mp[s.substr(i, 10)] = 0;
            }
        }
        return res;
    }
};
