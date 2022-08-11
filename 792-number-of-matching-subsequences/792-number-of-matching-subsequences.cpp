class Solution {
public:
    bool isSubsequence(string t, string s) {
        int n = s.size(), m = t.size();
        if(n > m){
            return false;
        }
        if(n == 0){
            return true;
        }
        int j = 0;
        for(int i = 0; i < m; i++) {
            if(t[i] == s[j]){
                j++;
            }
            if(j >= n){
                return true;
            }
        }
        return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int>mp;
        for(auto x : words) {
            mp[x]++;
        }
        int count = 0;
        for(auto it : mp) {
            if(isSubsequence(s, it.first)){
                count+=it.second;
            }
        }
        return count;
    }
};
