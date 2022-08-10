class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
        for(int i = 0; i < k; i++){
            res += cardPoints[i];
        }
        int currSum = res;
        for(int i = k-1; i>= 0; i--){
            currSum -= cardPoints[i];
            currSum += cardPoints[cardPoints.size()-k+i];
            res = max(res, currSum);
        }
        return res;
    }
};

