class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int v : nums){
            if(v >= 0) pos.push_back(v);
            else neg.push_back(v);
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < pos.size() && j < neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        return ans;
    }
};