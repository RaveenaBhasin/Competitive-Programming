class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp; 
        for(auto c : s) {
            mp[c]++; 
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return mp[a] > mp[b] || (mp[a] == mp[b] && a < b);
        });
        return s;
    }
};