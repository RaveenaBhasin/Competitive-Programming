class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int>mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<bool>vis(26, false);
        stack<char>st;
        for(auto it : s){
            mp[it]--;
            if(vis[it-'a']){
                continue;
            }
            char x = it;
            while(st.size() > 0 && st.top() > x && mp[st.top()] > 0){
                char popped = st.top();
                st.pop();
                vis[popped - 'a'] = false;
            }
            st.push(x);
            vis[x - 'a'] = true;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


