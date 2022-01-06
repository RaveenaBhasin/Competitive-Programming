class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>curr(1001);
        for(int i = 0; i < trips.size(); i++) {
            int x = trips[i][1];
            int y = trips[i][2];
            for(int j = x; j < y; j++) {
                curr[j] += trips[i][0];
            }
        }
        for(int i = 0; i <= 1000; i++) {
            if(curr[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};