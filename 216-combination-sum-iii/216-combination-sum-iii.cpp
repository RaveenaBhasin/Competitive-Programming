class Solution {
public:
    vector<vector<int>>powerSet;
    void validCombo(vector<int>&currSet, int currIndex, int k, int n) {
        if(n < 0 || currSet.size() > k){
            return;
        }
        if(n == 0 && currSet.size() == k){
            powerSet.push_back(currSet);
            return;
        }
        for(int i = currIndex; i <= 9; i++){
            currSet.push_back(i);
            validCombo(currSet, i+1, k, n - i);
            currSet.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //vector<vector<int>>powerSet;
        vector<int>possibleSet;
        validCombo(possibleSet, 1, k, n);
        return powerSet;
    }
};

