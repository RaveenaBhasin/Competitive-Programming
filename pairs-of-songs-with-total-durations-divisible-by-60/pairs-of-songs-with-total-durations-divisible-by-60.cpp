class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int>res(60,0);
        int ans = 0;
        for(int i=0; i<n;i++)
        {
            int cur = time[i]%60;
            ans += res[(60-cur)%60];
            res[cur]++;
        }
        return ans;
    }
};