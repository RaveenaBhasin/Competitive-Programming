class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;
        int res = 0;
        for(int i = 0; i < words.size(); i++) {
            string curr = words[i];
            string rev = curr;
            reverse(rev.begin(), rev.end());
            if(mp[rev]) {
                res += 4;
                mp[rev]--;
            }
            else mp[curr]++;
        }
        //checking existence of single occurrence
        int flag = 0;
        for(auto it: mp){
            if(it.second > 0) {
                string s = it.first;
                if(s[0] == s[1]) {
                    flag = 1;
                }
            }
        }
        if(flag) return res+=2;
        return res;
    }
};

