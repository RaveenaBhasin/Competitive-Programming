class Solution {
public:
    int diff_char(string&s1,string&s2){
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        return cnt;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> visited(bank.size(),false);
        queue<string> q;
        q.push(start);
        int step = 0;
        while(!q.empty()){
            int n = q.size();            
            while(n--){
                string curr = q.front();
                if(curr == end) return step;
                q.pop();
                for(int i = 0; i < bank.size(); i++){
                    if(visited[i]) continue;
                    int cnt = diff_char(bank[i],curr);
                    if(cnt < 2){
                        visited[i] = true;
                        q.push(bank[i]);
                    }
                }
            }step++;
        }
        return -1;
    }
};
