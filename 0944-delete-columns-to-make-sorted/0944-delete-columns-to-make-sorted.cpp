class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m-1; j++) {
                if(strs[j][i] > strs[j+1][i]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};