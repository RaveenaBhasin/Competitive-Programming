class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i = 0 ; i < nums.size(); i++){
            int start = nums[i];
            int end = nums[i];
            while(i + 1 < nums.size() && nums[i + 1] == nums[i] + 1){
                i++;
            }
            end = nums[i];
            if(start == end) ans.push_back(to_string(start));
            else ans.push_back(to_string(start)+"->"+to_string(end));
        }
        return ans;
    }
};